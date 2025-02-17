#include <iostream>
#include <string>

using namespace std;

// Clase base Vehiculo
class Vehiculo {
private:
    string marca;
    string modelo;
    double precio;

public:
    Vehiculo(string _marca, string _modelo, double _precio)
        : marca(_marca), modelo(_modelo), precio(_precio) {
    }

    virtual void mostrarInfo() const {
        cout << "Vehículo: " << marca << " " << modelo << ", Precio: Q" << precio;
    }

    // Métodos get
    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    double getPrecio() const { return precio; }

    // Métodos set
    void setMarca(string _marca) { marca = _marca; }
    void setModelo(string _modelo) { modelo = _modelo; }
    void setPrecio(double _precio) { precio = _precio; }

    // Destructor virtual
    virtual ~Vehiculo() {}
};

// Clase Automovil (hereda de Vehiculo)
class Automovil : public Vehiculo {
private:
    int numPuertas;

public:
    Automovil(string _marca, string _modelo, double _precio, int _numPuertas)
        : Vehiculo(_marca, _modelo, _precio), numPuertas(_numPuertas) {
    }

    void mostrarInfo() const override {
        Vehiculo::mostrarInfo();
        cout << ", Puertas: " << numPuertas << endl;
    }
};

// Clase Motocicleta (hereda de Vehiculo)
class Motocicleta : public Vehiculo {
private:
    int cilindrada;

public:
    Motocicleta(string _marca, string _modelo, double _precio, int _cilindrada)
        : Vehiculo(_marca, _modelo, _precio), cilindrada(_cilindrada) {
    }

    void mostrarInfo() const override {
        Vehiculo::mostrarInfo();
        cout << ", Cilindrada: " << cilindrada << "cc" << endl;
    }
};

// Clase Camioneta (hereda de Vehiculo)
class Camioneta : public Vehiculo {
private:
    double capacidadCarga;

public:
    Camioneta(string _marca, string _modelo, double _precio, double _capacidadCarga)
        : Vehiculo(_marca, _modelo, _precio), capacidadCarga(_capacidadCarga) {
    }

    void mostrarInfo() const override {
        Vehiculo::mostrarInfo();
        cout << ", Capacidad de carga: " << capacidadCarga << " toneladas" << endl;
    }
};

// Clase Cliente
class Cliente {
private:
    string nombre;
    int edad;

public:
    Cliente(string _nombre, int _edad) : nombre(_nombre), edad(_edad) {}

    void comprarVehiculo(const Vehiculo& v) const {
        cout << "Cliente " << nombre << " ha comprado un " << v.getMarca() << " " << v.getModelo() << endl;
    }
};

int main() {
    // Creación de vehículos
    Automovil auto1("Toyota", "Corolla", 25000, 4);
    Motocicleta moto1("Yamaha", "R1", 18000, 1000);
    Camioneta camioneta1("Ford", "Ranger", 30000, 1.5);

    // Mostrar información de los vehículos
    auto1.mostrarInfo();
    moto1.mostrarInfo();
    camioneta1.mostrarInfo();

    // Creación de un cliente
    Cliente cliente1("Juan", 30);

    // Simulación de la compra de un vehículo
    cliente1.comprarVehiculo(auto1);

    return 0;
}
