#define WINVER 0x0500
#include <stdio.h>
#include <windows.h>
#include <windowsx.h>


#define DIV 1048576

void main()
{
 printf("       :@@@     @@@@@@@@@@  @@.    `@@      @@@@@@       @@@@@ \n");
printf("       @@@@     @@@@@@@@@@  @@'    :@@    ,@@@@@@@@,   `@@@@@@+      \n");
printf("      `@@@@'    @@@@@@@@@@  @@'    :@@   `@@@#  @@@@   @@@   #+      \n");
printf("      #@#@@@       .@@.     @@'    :@@   @@@     :@@#  @@#           \n");
printf("      @@.,@@       .@@.     @@'    :@@   @@#      @@@  @@@           \n");
printf("     .@@  @@#      .@@.     @@'    :@@  .@@,      @@@  @@@@#         \n");
printf("     #@#  @@@      .@@.     @@@@@@@@@@  :@@.      #@@   @@@@@+       \n");
printf("     @@.  ,@@`     .@@.     @@@@@@@@@@  :@@.      #@@    #@@@@#      \n");
printf("    ,@@    @@#     .@@.     @@'    :@@  ,@@,      @@@      #@@@      \n");
printf("    @@@@@@@@@@     .@@.     @@'    :@@   @@#      @@@       '@@.     \n");
printf("    @@@@@@@@@@,    .@@.     @@'    :@@   @@@     +@@'       :@@`     \n");
printf("   :@@      @@@    .@@.     @@'    :@@   '@@@'  @@@@  `@@  :@@@      \n");
printf("   @@@      @@@    .@@.     @@'    :@@    @@@@@@@@@    @@@@@@@.      \n");
printf("   @@,      ,@@     @@      @@.    `@@      @@@@@'      @@@@@        \n\n\n\n\n");

    char nomeEmpresa[50];
    printf("DIGITE O NOME DA EMPRESA: ");gets(nomeEmpresa);
    FILE *requisitos;
    requisitos = fopen("requisitos.txt", "a+");


    MEMORYSTATUSEX statex;

    statex.dwLength = sizeof (statex);

    GlobalMemoryStatusEx (&statex);

    SYSTEM_INFO siSysInfo;

    GetSystemInfo(&siSysInfo);
    printf("\n\nOs requisitos minimos sao:\n\nPara servidor: Um processador com 2 nucleos ou mais e 2Gb de memoria RAM ou mais\n\nPara terminal: Um processador com 1 nucleo ou mais e 1Gb de RAM ou mais\n\n");

    fprintf(requisitos, "Nome da Empresa: %s\nNucleos: %u\nTipo do Processador: %u\nTotal de Memoria: %d\n\n", nomeEmpresa, siSysInfo.dwNumberOfProcessors, siSysInfo.dwProcessorType, statex.ullTotalPhys/DIV);


    if(siSysInfo.dwNumberOfProcessors>=2 && statex.ullTotalPhys/DIV>=2048)
    {
        system("COLOR F2");
        printf("Voce possui um processador de %d nucleos\n", siSysInfo.dwNumberOfProcessors);
        printf("Voce possui %dMb de memoria RAM\n\n\n\n", statex.ullTotalPhys/DIV);
        printf("\t\t\t\t|====================================================|\n");
        printf("\t\t\t\t|=====SISTEMA COMPATIVEL COM TERMINAL E SERVIDOR=====|\n");
        printf("\t\t\t\t|====================================================|\n");
    }
    else if (siSysInfo.dwNumberOfProcessors<2 && siSysInfo.dwNumberOfProcessors>1 && statex.ullTotalPhys<2048 && statex.ullTotalPhys>1024)
    {
        system("COLOR F2");
        printf("Voce possui um processador de %d nucleos\n", siSysInfo.dwNumberOfProcessors);
        printf("Voce possui %dMb de memoria RAM\n\n\n\n", statex.ullTotalPhys/DIV);
        printf("\t\t|=========================================|\n");
        printf("\t\t|=====SISTEMA COMPATIVEL COM TERMINAL=====|\n");
        printf("\t\t|=========================================|\n");
    }
    else
    {
        system("COLOR FC");
        printf("Voce possui um processador de %d nucleos\n", siSysInfo.dwNumberOfProcessors);
        printf("Voce possui %dMb de memoria RAM\n\n\n\n", statex.ullTotalPhys/DIV);
        printf("\t\t|==============================|\n");
        printf("\t\t|=====SISTEMA INCOMPATIVEL=====|\n");
        printf("\t\t|==============================|\n");
    }

    getchar();
}
