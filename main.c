#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#define FILAS_TABLERO 10
#define COLUMNAS_TABLERO 10
#define X_AGENTE 9      // Columnas
#define Y_AGENTE 0      // Filas
#define X_META 1
#define Y_META 9

struct Agente {
    int x;
    int y;
    float combustible;
    bool m1;
    bool m2;
    bool m3;
    bool m4;
};

void inicio() {
    system("cls");
    printf("  _  __     _   _                 _                                   _       \n");
    printf(" | |/ /__ _| |_(_) __ _   _   _  | | __ _   _ __ ___  _   _  ___ _ __| |_ ___ \n");
    printf(" | ' // _` | __| |/ _` | | | | | | |/ _` | | '_ ` _ \\| | | |/ _ \\ '__| __/ _ \\\n");
    printf(" | . \\ (_| | |_| | (_| | | |_| | | | (_| | | | | | | | |_| |  __/ |  | ||  __/\n");
    printf(" |_|\\_\\__,_|\\__|_|\\__,_|  \\__, | |_|\\__,_| |_| |_| |_|\\__,_|\\___|_|   \\__\\___|\n");
    printf("                          |___/                                               \n\n");

    printf("                                                        Una novela terminal\n\n\n");

    printf("Presiona ENTER para comenzar ");
    getchar();
    system("cls");

    printf("En abril de 2100, investigadores del Centro de Estudios Astronómicos de Oztotlán (CEA) descubrieron, en la superficie de Neptuno, unas manchas oscuras que cambiaban de forma hasta cuatro veces al día. Tres meses después, en julio, la modesta misión Oztotlán-I fue puesta en órbita. ");
    getchar();
    system("cls");

    printf("La tripulación consistía en tres astronautas humanos y un androide modelo KH98-4 llamada Katia. ");
    getchar();
    system("cls");

    printf("Tras un viaje de poco menos de veinte horas, cuando la nave estaba por aterrizar, algo la detuvo. Por unas horas la corriente se cortó, y ni siquiera el equipo del CEA encargado de monitorear la misión desde la Tierra pudo brindar a los astronautas alguna explicación que aplacara su temor y desesperación. ");
    getchar();
    system("cls");

    printf("El CEA se apoyó principalmente en Katia para intentar estudiar aquella fuerza fantasma que había interceptado la nave. El enrojecimiento en los ojos de los astronautas había venido acompañado por una ceguera agónica. ");
    getchar();
    system("cls");

    printf("Si bien al principio no encontró nada inusual, Katia terminó detectando en el oxígeno de la nave una partícula de propiedades del todo ajenas a las de los elementos presentes en la Tierra y otros rincones del espacio conocido. A su presencia en los pulmones de los humanos se atribuyó el desarrollo de una conducta cada vez más errática y agresiva; además, parecían haber perdido la capacidad de comunicarse verbalmente. ");
    getchar();
    system("cls");

    printf("Decididos a dejarlos morir y a olvidar todo lo sucedido con la desafortunada misión Oztotlán-I, los técnicos del CEA apagaron a Katia y activaron el mecanismo de autodestrucción de la nave. Los ojos de los humanos habían explotado, y de las cuencas vacías brotaba un líquido negro y espeso, interminable. ");
    getchar();
    system("cls");

    printf("Katia despertó y, mientras recorría la nave sumida en la oscuridad, pensaba en su soledad como si lo hiciera por primera vez. Buscaba los cuerpos de sus compañeros cuando el mecanismo de autodestrucción fue súbitamente detenido. ");
    getchar();
    system("cls");

    printf("“Los demás tenían unas monedas con las que, según los técnicos, se podía llevar un seguimiento total de sus signos vitales. Debo encontrarlas”, pensó. Su ubicación había sido marcada con una M en el mapa de la sala de control.\n“Me queda poco combustible. Aunque debería ser suficiente para recoger todas las monedas, hay una estación, señalada con una C, donde puedo recargar. Después puedo seguir explorando la nave; la puerta se encuentra en el otro extremo de la sala”. ");
    getchar();
    system("cls");
}

void fin() {
    system("cls");
    printf("“Bzzt, bzzt”. La consola de comunicaciones emitió un sonido débil, que Katia reconoció como el intento de establecer contacto con ella. Apresurada, se dirigió hacia la máquina. ");
    getchar();

    printf("\n-Soy yo, soy yo: Katia –dijo. ");
    getchar();

    printf("-¿Katia? ¿Pero cómo... ? -Había mucha interferencia, y la voz era la de G o R. ");
    getchar();

    printf("-¿Qué sucedió? ");
    getchar();

    printf("-No... tú... quince minutos... muerte... ");
    getchar();

    printf("-No puedo escuchar claramente. ");
    getchar();

    printf("-Regreses... ahora la nave... antes. ");
    getchar();

    printf("-¿Intentarán llevarnos de regreso? ");
    getchar();

    printf("-Ahora... nada ni nadie... ti misma. ");
    getchar();
    system("cls");

    printf("La comunicación terminó abruptamente. Sorprendida, aterrada, Katia comenzó a sentir que algo apretaba la nave como si se tratara de una esfera de papel y buscó tras las ventanas algo que pudiera provocarle un terror indescriptible.\n\n\n\n\n");
}

// EL tablero se inicializa casi vacío, salvo por las fichas que representan los objetos de interés
void crear_tablero(char tablero[COLUMNAS_TABLERO][FILAS_TABLERO], struct Agente agente) {
    for (int i = 0; i < FILAS_TABLERO; i++) {
        for (int j = 0; j < COLUMNAS_TABLERO; j++) {
            tablero[i][j] = ' ';
        }
    }
    // Agente
    tablero[agente.y][agente.x] = 'o';

    // Meta
    tablero[Y_META][X_META] = '*';

    // Combustible
    tablero[7][7] = 'C';

    // Monedas
    tablero[0][0] = 'M';
    tablero[6][3] = 'M';
    tablero[9][8] = 'M';
    tablero[2][9] = 'M';

    // Paredes
    tablero[3][0] = '#';
    tablero[3][1] = '#';
    tablero[3][2] = '#';
    tablero[3][3] = '#';

    tablero[7][0] = '#';
    tablero[7][1] = '#';
    tablero[7][2] = '#';
    tablero[7][3] = '#';

    tablero[3][7] = '#';
    tablero[4][7] = '#';
    tablero[5][7] = '#';

    tablero[6][7] = '#';
    tablero[6][8] = '#';
    tablero[6][9] = '#';
    tablero[7][8] = '#';
    tablero[7][9] = '#';

    tablero[Y_META][X_META-1] = '#';
    tablero[Y_META][X_META+1] = '#';
}

// Imprimir el tablero en consola
void mostrar_tablero(char tablero[COLUMNAS_TABLERO][FILAS_TABLERO]) {
    printf("\n-----------------------------------------\n");
    for (int i = 0; i < FILAS_TABLERO; i++) {
        printf("|");
        for (int j = 0; j < COLUMNAS_TABLERO; j++) {
            if (j < COLUMNAS_TABLERO) {
                printf(" %c |", tablero[i][j]);
            }
            else {
                printf(" %c ", tablero[i][j]);
            }
        }
        if (i < FILAS_TABLERO) {
            printf("\n-----------------------------------------\n");
        }
    }
    printf("\n\n");
}

// Condiciones de éxito
bool determinar_fin(struct Agente agente) {
    int x = agente.x;
    int y = agente.y;

    if (x == X_META && y == Y_META && agente.m1 == true && agente.m2 == true && agente.m3 == true && agente.m4 == true) {
        return true;
    }
    return false;
}

// Movimiento del personaje
bool mover_agente(char tablero[COLUMNAS_TABLERO][FILAS_TABLERO], struct Agente *agente) {
    // Posiciones iniciales
    int x = agente->x;
    int y = agente->y;

    // Para actualizar posiciones
    int nuevo_x = x;
    int nuevo_y = y;

    // Movimiento a ejecutar
    char movimiento;

    printf("Combustible disponible: %.1lf L\n", agente->combustible);
    printf("Monedas: [%d/4]\n", agente->m1 + agente->m2 + agente->m3 + agente->m4);
    printf("Movimiento (Con las teclas W, A, S, D. Pulsa ENTER para confirmar. Escribe 'X' para salir): ");
    fflush(stdin);
    scanf(" %c", &movimiento);
    printf("\n");

    // Posibles movimientos del agente
    if (agente->combustible > 0 && (movimiento == 'w' || movimiento == 'W'))
        nuevo_y--;
    else if (agente->combustible > 0 && (movimiento == 's' || movimiento == 'S'))
        nuevo_y++;
    else if (agente->combustible > 0 && (movimiento == 'a' || movimiento == 'A'))
        nuevo_x--;
    else if (agente->combustible > 0 && (movimiento == 'd' || movimiento == 'D'))
        nuevo_x++;
    else if (agente->combustible > 0 && (movimiento == 'x' || movimiento == 'X'))
        return false;

    // Detección de paredes
    if (tablero[nuevo_y][nuevo_x] == '#') {
        return true;
    }

    // Detección de bordes del tablero
    if (nuevo_x < 0 || nuevo_x >= COLUMNAS_TABLERO || nuevo_y < 0 || nuevo_y >= FILAS_TABLERO)
        return true;

    // Recargar gasolina
    if (agente->x == 7 && agente->y == 7)
        agente->combustible += 1.5;

    // Recoger monedas
    if (agente->x == 0 && agente->y == 0)
        agente->m1 = true;
    
    if (agente->x == 3 && agente->y == 6)
        agente->m2 = true;
    
    if (agente->x == 8 && agente->y == 9)
        agente->m3 = true;
    
    if (agente->x == 9 && agente->y == 2)
        agente->m4 = true;

    // Borrar la posición anterior
    tablero[y][x] = ' ';

    // Disminuir la cantidad de combustible con cada movimiento válido
    if (agente->combustible > 0) {
        agente->combustible -= 0.5;
    }
    else {
        return false;
    }

    // Actualizar la posición del agente de forma interna
    agente->x = nuevo_x;
    agente->y = nuevo_y;
    tablero[nuevo_y][nuevo_x] = 'o';

    return true;
}

// Bucle que llama al resto de las funciones y rastrea el estado de la partida
bool juego(char tablero[COLUMNAS_TABLERO][FILAS_TABLERO], struct Agente *agente) {
    crear_tablero(tablero, *agente);
    bool finalizado = false;
    bool continuar = true;

    while (!finalizado && continuar) {
        system("cls");
        mostrar_tablero(tablero);
        continuar = mover_agente(tablero, agente);
        finalizado = determinar_fin(*agente);
    }

    system("cls");
    mostrar_tablero(tablero);

    // Casos en los que la partida es finalizada
    if (agente->combustible == 0) {
        printf("¡Ya no hay combustible!\n");
        return false;
    }
    else if (!continuar) {
        printf("Partida finalizada.\n");
        return false;
    }

    return true;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    struct Agente Katia = {
        X_AGENTE,
        Y_AGENTE,
        20,
        false,
        false,
        false,
        false
    };

    char tablero[COLUMNAS_TABLERO][FILAS_TABLERO];

    inicio();
    bool final_juego = juego(tablero, &Katia);

    if (final_juego)
        fin();

    return 0;
}