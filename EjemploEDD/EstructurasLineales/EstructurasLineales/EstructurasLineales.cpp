#include "pch.h"
#include "List.h"
#include "ListaCartas.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    List* myList = new List();
    ListaCartas* mazo = new ListaCartas();

    int opt = 0;

    do {
        Console::WriteLine("Seleccione una opcion");
        Console::WriteLine("1. Insertar dato");
        Console::WriteLine("2. Ver datos guardados");
        Console::WriteLine("3. Insertar nueva Carta");
        Console::WriteLine("4. Obtener una carta al azar");
        Console::WriteLine("5. Listar cartas");
        Console::WriteLine("6. Salir");

        opt = Convert::ToInt32(Console::ReadLine());

        switch (opt) {
        case 1: {
            Console::WriteLine("Ingrese el dato");
            myList->Add( Convert::ToInt32( Console::ReadLine() ) );
            Console::WriteLine("Dato Guardado Exitosamente");
        }break;

        case 2: {
            Console::WriteLine("***********************");
            Console::WriteLine("El listado de casos es:");
            for (int i = 0; i < myList->Count(); i++) {
                Console::WriteLine("[" + i + "] -> " + myList->GetItem(i));
            }
            Console::WriteLine("***********************");
        }break;

        case 3: {
            Console::WriteLine("Ingrese los datos de la carta");
            Carta* myCarta = new Carta();
            Console::WriteLine("Ingrese numero de la carta");
            myCarta->setNumero( Convert::ToInt32(Console::ReadLine() ) );

            Console::WriteLine("Ingrese el color de la carta: R / N");
            myCarta->setColor( Convert::ToChar(Console::ReadLine()) );


            Console::WriteLine("Ingrese el simbolo de la carta: C / E / T / D");
            myCarta->setSimbolo(Convert::ToChar(Console::ReadLine()));

            mazo->Add(myCarta);

            Console::WriteLine("Carta Guardado Exitosamente");
        }break;

        case 4: {
            Console::WriteLine("Se esta escogiendo una carta al azar");
            if (mazo->Count() == 0) {
                Console::WriteLine("El mazo esta vacio");
            }
            else {
                int random = (gcnew Random())->Next(mazo->Count());
                Carta* seleccionada = mazo->GetItem(random);

                Console::WriteLine("La carta es: ");
                Console::WriteLine("" + seleccionada->getNumero() + " - " + Convert::ToChar( seleccionada->getColor() ) + " - " + Convert::ToChar(seleccionada->getSimbolo()));
            }

        }break;

        case 5: {
            Console::WriteLine("Mostrando todas las cartas guardadas");
            for (int i = 0; i < mazo->Count(); i++) {
                Console::WriteLine("La carta en la posicion : " + i + " es: ");
                Console::WriteLine("" + mazo->GetItem(i)->getNumero() + " - " + Convert::ToChar( mazo->GetItem(i)->getColor() ) + " - " + Convert::ToChar( mazo->GetItem(i)->getSimbolo() ) );
            }
        }break;

        case 6: {
            Console::WriteLine("Hasta Luego!");
        }break;

        default: {
            Console::WriteLine("Opcion no valida");
        }break;
        }

    } while (opt != 6);

    return 0;
}
