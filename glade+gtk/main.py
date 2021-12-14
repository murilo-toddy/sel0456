#!/usr/bin/python3

import math

import gi

gi.require_version("Gtk", "3.0")

from gi.repository import Gtk, Gdk, GLib, GObject

builder = Gtk.Builder()

class Handler:
    def onDestroy(self, *args):
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

    def on_check1_toggled(self, wdg):
        print("Check1 alterado")

    def on_adj1_changed(self, wdg):
        print("Adjustment adj1 alterado")

builder.add_from_file("main.glade")

builder.connect_signals(Handler())

window = builder.get_object('window1')

window.show_all()

Gtk.main()
