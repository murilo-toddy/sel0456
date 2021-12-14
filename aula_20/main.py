#!/usr/bin/python3

import math

import gi

gi.require_version("Gtk", "3.0")

from gi.repository import Gtk, Gdk, GLib, GObject

builder = Gtk.Builder()

filename = None

class Handler:
    def on_window1_destroy(self, *args):
        Gtk.main_quit()

    def on_button1_clicked(self, button):
        global builder
        print('Button1 clicked')
        v = builder.get_object('val1')
        txt = v.get_text()
        print('Valor do diâmetro: {}'.format(txt))
        try:
            print('Área: ' + str(math.pi/4*int(txt)**2) + '[unidade]^2')
        except ValueError:
            print ('Entrada inválida')
        chk = builder.get_object('check1')
        if chk.get_active():
            print ('Check1 ativo')
        else:
            print('Check1 inativo')

    def on_combo1_changed(sefl, wdg):
        pass

    def on_check1_toggled(self, wdg):
        print("Check1 alterado")

    def on_adj1_value_changed(self, wdg):
        print("Adjustment adj1 alterado")
        x = wdg.get_value()
        print("O valor de adj1 é {}, x^2 = {}".format(x, x**2))

    def on_menu_open_activate(self, wdg):
        print("Menu Open activate")
        dialog = builder.get_object("opendialog")
        dialog.show_all()

    def on_open_clicked(self, wdg):
        print("Open clicked")
        dialog = builder.get_object("opendialog")
        dialog.show_all()

    def on_cancel_clicked(self, wdg):
        global filename
        dialog = builder.get_object("opendialog")
        dialog.hide()
        filename = None

    def on_ok_clicked(self, wdg):
        global filename
        dialog = builder.get_object("opendialog")
        dialog.hide()
        filename = dialog.get_filename()
        print(f'filename = {filename}')

    # https://python-gtk-3-tutorial.readthedocs.io/en/latest/dialogs.html
    def on_open2_clicked(self, wdg):
        global window
        dialog = Gtk.FileChooserDialog(title = "Escolha um arquivo", parent=window, action=Gtk.FileChooserAction.OPEN)
        dialog.add_buttons(
            Gtk.STOCK_CANCEL,
            Gtk.ResponseType.CANCEL,
            Gtk.STOCK_OPEN,
            Gtk.ResponseType.OK,
        )
        response = dialog.run()
        if response == Gtk.ResponseType.OK:
            print("Open clicked")
            print("File selected: " + dialog.get_filename())
        elif response == Gtk.ResponseType.CANCEL:
            print("Cancel clicked")

        dialog.destroy()


builder.add_from_file("main.glade")

builder.connect_signals(Handler())

window = builder.get_object('window1')

window.show_all()

Gtk.main()
