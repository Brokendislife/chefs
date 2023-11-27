#include <iostream>
#include <string>
#include <climits>
#include <map>

class Persona {
public:
	int identificacion;
	std::string nombre;
	std::string apellido;
	int edad;
	int salario;
};

class Cocinero : public Persona {
public:
	std::string tipoComida;

	Cocinero() {
		tipoComida = "Ninguno";
	}

	Cocinero(int id, std::string nom, std::string ape, int ed, int sal, std::string tipo) {
		identificacion = id;
		nombre = nom;
		edad = ed;
		salario = sal;
		tipoComida = tipo;
	}
};

void mostrarCocineros(const Cocinero cocineros[], int cantidadCocineros) {
	std::cout << "Lista de Cocineros:\n";
	for (int i = 0; i < cantidadCocineros; ++i) {
		std::cout << "ID: " << cocineros[i].identificacion << ", Nombre: " << cocineros[i].nombre << " " << cocineros[i].apellido << ", Edad: " << cocineros[i].edad << ", Salario: " << cocineros[i].salario << ", Tipo de comida: " << cocineros[i].tipoComida << "\n";
	}
}

void mostrarCocineroMayorEdad(const Cocinero cocineros[], int cantidadCocineros) {
	int mayorEdad = 0;
	int ubicacion = 0;

	if (cantidadCocineros == 0) {
		std::cout << "No hay cocineros registrados.\n";
		return;
	}

	mayorEdad = cocineros[0].edad;

	for (int i = 0; i < cantidadCocineros; i++) {
		std::cout << cocineros[i].edad;
		if (cocineros[i].edad > mayorEdad) {
			mayorEdad = cocineros[i].edad;
			ubicacion = i;
		}
	}

	std::cout << "Cocinero con mayor edad:\n";
	std::cout << "Nombre: " << cocineros[ubicacion].nombre << " " << cocineros[ubicacion].apellido << ", Edad: " << cocineros[ubicacion].edad << "\n";

	return;
}

void mostrarCocineroMenorSalario(const Cocinero cocineros[], int cantidadCocineros) {
	int menorSalario = 0;
	int ubicacion = 0;

	if (cantidadCocineros == 0) {
		std::cout << "No hay cocineros registrados.\n";
		return;
	}

	menorSalario = cocineros[0].edad;

	for (int i = 0; i < cantidadCocineros; i++) {
		if (cocineros[i].salario < menorSalario) {
			menorSalario = cocineros[i].salario;
			ubicacion = i;
		}
	}

	std::cout << "Cocinero con mayor edad:\n";
	std::cout << "Nombre: " << cocineros[ubicacion].nombre << " " << cocineros[ubicacion].apellido << ", Edad: " << cocineros[ubicacion].edad << "\n";

	return;
}

void mostrarCocinerosPorTipo(const Cocinero cocineros[], int cantidadCocineros) {
	// Usar std::map para almacenar la cantidad de cocineros por cada tipo de comida
	std::map<std::string, int> cantidadPorTipo;

	// Contar la cantidad de cocineros por tipo de comida
	for (int i = 0; i < cantidadCocineros; ++i) {
		cantidadPorTipo[cocineros[i].tipoComida]++;
	}

	// Mostrar la cantidad de cocineros por cada tipo de comida
	std::cout << "Cocineros por tipo de comida:\n";
	for (const auto& pair : cantidadPorTipo) {
		std::cout << "Tipo: " << pair.first << ", Cantidad: " << pair.second << "\n";
	}
}

int main() {
	const int maxCocineros = 100; 
	Cocinero cocineros[maxCocineros];
	int cantidadCocineros = 0;
	int opciones;
	
	retorno:

	std::cout << "Menu!\n";
	std::cout << "Opcion 1: Ingresar un nuevo cocinero\n";
	std::cout << "Opcion 2: Mostrar todos los cocineros\n";
	std::cout << "Opcion 3: Mostrar nombre y apellido de cocinero con mayor edad\n";
	std::cout << "Opcion 4: Mostrar el cocinero con el menor salario\n";
	std::cout << "Opcion 5: Mostrar cuantos cocineros hay por cada cargo (Tipo de comida y Cantidad de cocineros)\n";
	std::cout << "Opcion 6: Salir\n";
	std::cout << "Digita tu opcion: ";

	std::cin >> opciones;
	if (opciones > 6 || opciones < 1) {
		std::cout << "Digita una opcion valida\n";
		goto retorno;
	}

	switch (opciones)
	{
	case 1: {
		// Ingresar un nuevo cocinero
		int id, ed, sal;
		std::string nom, ape, tipo;

		std::cout << "Ingrese la identificacion: ";
		std::cin >> id;
		// Verificar si la identificación ya existe
		bool existe = false;

		for (int i = 0; i < cantidadCocineros; ++i) {
			if (cocineros[i].identificacion == id) {
				existe = true;
			}
		}

		if (existe) {
			std::cout << "El cocinero con identificacion " << id << " ya existe. Por favor, ingrese otra identificacion.\n";
			break;
		}

		std::cout << "Ingrese el nombre: ";
		std::cin >> nom;

		std::cout << "Ingrese el apellido: ";
		std::cin >> ape;

		std::cout << "Ingrese la edad: ";
		std::cin >> ed;

		std::cout << "Ingrese el salario: ";
		std::cin >> sal;

		std::cout << "Ingrese el tipo de comida: ";
		std::cin >> tipo;

		// Crear una instancia de Cocinero y agregarla al array de cocineros
		Cocinero nuevoCocinero(id, nom, ape, ed, sal, tipo);
		cocineros[cantidadCocineros] = nuevoCocinero;
		cantidadCocineros++;



		std::cout << "Cocinero ingresado correctamente.\n";
		goto retorno;
	}
	case 2:
		mostrarCocineros(cocineros, cantidadCocineros);
		goto retorno;

	case 3:
		mostrarCocineroMayorEdad(cocineros, cantidadCocineros);
		goto retorno;

	case 4:
		mostrarCocineroMenorSalario(cocineros, cantidadCocineros);
		goto retorno;
	case 5:
		mostrarCocinerosPorTipo(cocineros, cantidadCocineros);
		goto retorno;
	default:
		break;
	}

	return 0;
}
