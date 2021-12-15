import gi

gi.require_version("Gtk", "3.0")
from gi.repository import Gtk

# Material resistivity in nOhm
RHO_ALUMINUM = 26.5
RHO_COPPER   = 16.8
RHO_GOLD     = 24.4
RHO_SILVER   = 15.9


def invalid_entry():
    main.main_obj("error").show_all()
    print("\n-- Invalid Entry --")
    print("Check input data and try again")
    print()


class Handler:
    def on_window_close(self, *args):
        print("App closed")
        Gtk.main_quit()

    def on_error_button_pressed(self, button):
        main.main_obj("error").hide()
        print("Error button pressed")

    def on_button_pressed(self, button):
        print("Button pressed")

        material = main.main_obj("material").get_text()

        try:
            current = float(main.main_obj("current").get_text())
            voltage = float(main.main_obj("voltage").get_text())
            length = float(main.main_obj("length").get_text())

        except ValueError:
            invalid_entry()
            return

        if current <= 0 or voltage <= 0 or length <= 0:
            invalid_entry()
            return

        print("\n-- Information --")
        print(f"Current: {current} A")
        print(f"Voltage: {voltage} V")
        print(f"Length: {length} m")
        print(f"Material: {material}")
        print()

        if material == "Alumínio": RHO = RHO_ALUMINUM
        if material == "Cobre":    RHO = RHO_COPPER
        if material == "Ouro":     RHO = RHO_GOLD
        if material == "Prata":    RHO = RHO_SILVER

        res = 0.25 * voltage / current
        area = RHO * length / res / 100

        print(f"Secction: {area}")
        print()

        main.main_obj("area").set_text(str(round(area, 2)))

                

class MainWindow:
    def __init__(self):
        print("Creating window")
        self.builder = Gtk.Builder()
        self.builder.add_from_file("main.glade")
        self.builder.connect_signals(Handler())

        self.main_window()

        print("Setting default values\n")
        self.add_default_values()


    def main_window(self):
        self.main_obj = self.builder.get_object
        self.main_obj("window1").show_all()


    def add_default_values(self):
        self.main_obj("current").set_text("1")
        self.main_obj("voltage").set_text("127")
        self.main_obj("length").set_text("100")
        self.main_obj("material").set_text("Alumínio")


        
if __name__ == '__main__':
    main = MainWindow()
    Gtk.main()