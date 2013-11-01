/* 
 * File:   main.c
 * Author: Per
 *
 * Created on den 29 oktober 2013, 15:05
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h";
/*
 * 
 */
int main(int argc, char** argv) {
    do{
        show_menu();
        run_selection(get_selection());
    }while(pause());
    return 0;
}

