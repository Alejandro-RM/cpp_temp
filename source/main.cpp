#include <filesystem>
#include <iomanip>
#include <ostream>
#include <string>
#include <gtkmm.h>

template<typename T>
using SP = Glib::RefPtr<T>;

template<typename T>
T& operator*(SP<T> smart_ptr) {
  return *smart_ptr.get();
}

class Item {
private:
  std::string id;
  std::string name;
  int in_stock;
  int buy_price;
  int sale_price;

public:
  Item(std::string id, std::string name, int in_stock, int buy_price, int sale_price) :
  id(id), name(name), in_stock(in_stock), buy_price(buy_price), sale_price(sale_price) {}

  bool operator==(const Item& item) const {
    return this->id == item.id;
  }

  bool operator<(const Item& item) const {
    return this->id < item.id;
  }

  friend std::ostream& operator<<(std::ostream& output, const Item& item) {
    return output << std::setiosflags(std::ios_base::right) 
      << "\tID: " << std::setw(20) << std::setfill('-') << item.id << '\n'
      << "\tNombre: " << std::setw(20) << std::setfill('-') << item.name << '\n'
      << "\tCantidad Almacenada: " << std::setw(20) << std::setfill('-') << item.in_stock << '\n'
      << "\tPrecio de Compra: " << std::setw(20) << std::setfill('-') << item.buy_price << '\n'
      << "\tPrecio de Venta: " << std::setw(20) << std::setfill('-') << item.sale_price << '\n';
  }
};

class ShopCPP {
private:
  SP<Gtk::Application> application;
  SP<Gtk::Builder> builder;
  SP<Gtk::Window> window;

public:
  ShopCPP(std::string application_ID, std::string window_ID, std::filesystem::path file) :
  application(Gtk::Application::create(application_ID)),
  builder(Gtk::Builder::create_from_file(file.string())),
  window(SP<Gtk::Window>::cast_dynamic(builder->get_object(window_ID))) {}

  int run() {
    return application->run(*window);
  }
};

#include <iostream>

int main(int argc, char** argv) {
  auto application = ShopCPP("Tienda CPP", "ApplicationWindow", "../assets/TiendaCPP.glade");
  Item item("0x0000", "Papas", 20, 20, 20);
  std::cout << item;
  return application.run();
}