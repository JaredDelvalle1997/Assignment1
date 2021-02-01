#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "leak_detector_c.h"
#include "sp21_cop3502_as1.h"




/*
    Context: Monster trainer are asking you advice about planning expeditions into various regions

    Objective of code: To estimate how many monsters of each type they can expect to capture in each region.

    Things I have:

        1. "Small Monster Index: Tells me the "name", "type, and "relative commonality"
            - The monster ABSOLUTE commonality is the same in each region.

        2. Atlas: Tells me about the relevant regions & which small monsters are present in them

    Trainers' given information:

        1. Each trainer tells me:
            a.) Which region they're visiting
            b.) How many monsters they intend to capture per region

    To estimate the number of a given monster "M" a trainer will capture in region "R":

        1. DIVIDE the relative population of "M" in "R" by "R"'s total relative population.
        2. MULTIPLE the result by the total number of captures the trainer intends per region.
        3. ROUND this RESULT to the nearest integer

    Things to build:

        1. The "Small Monster Index" Function
            a.) Name
            b.) Type
            c.) Relative Commonality

        2. The "Region Creation" Function
            a.) Name
            b.) Number of Monsters
            c.) Type of Monsters

        3. The "Trainers Creation" Function
            a.) Name
            b.) How many intended captures
            c.) How many Regions


*/
void remove_crlf(char *s);

int get_next_nonblank_line(FILE *ifp, char *buf, int max_length)
{
    buf[0] = '\0';

    while(!feof(ifp) && (buf[0] == '\0'))
    {
        fgets(buf, max_length, ifp);
        remove_crlf(buf);
    }

    if(buf[0] != '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void remove_crlf(char *s)
{
    char *t = s + strlen(s);

    /* t is now at s's null terminator. */

    t--;

    /* t now points to the last character of s.  (Importantly, we haven't changed s.) */

    /* We have two cases where t can end up to the left of s: if we're passed a zero-length string,
       or if literally the entire string is made up of \n and/or \r.  Stop everything if t ends up
       to the left of s to prevent bad things from happening in that case. */

    while((t >= s) && (*t == '\n' || *t == '\r')) {
        *t = '\0';  // ...clobber it by overwriting it with null, and...
        t--;        // decrement t *itself (i.e., change the pointed location)

        /* t now still points to the last character of s, and we keep going until it's something
           other than a CR or newline. */
    }
}





/* This function is meant to read the input file into the monster structure */
void read_monsters_into_struct(FILE *ipf, monster *m, char *buf)
{
    int id;
    char namebuf[256];
    char elementbuf[256];
    int population;

    sscanf("%s %s %d",namebuf, elementbuf, &population);

}

void sort_into_all_structs(FILE *ifp, monster *m, region *r, itinerary *i, trainer *t)
{
    char buf[256];

    char categories[] = {"monsters", "regions", "Trainers"};

    while(get_next_nonblank_line(ifp, buf, 255))
    {
        // Put Reading Formulas here
    }


}





/* Double pointer - utilitzed to allocate memory for dparray */
monster **new_monster_dparray(int n)
{
    return calloc(n, sizeof(monster *));

}

/* Constructor for new monster to go into 2-D Array for monsters */
monster *new_monster(int id, char *name, char *element, int population)
{


}

/* A void function with the purpose of freeing memory from an array where memory was previous allocated */
void dispose_dparray(monster **array)
{
    free(array);
}

int main()
{
    // atexit(report_mem_leak);

    FILE *opf;
    FILE *ipf;
    monster *monsters;

    char buf[256];


    /* Open up the input and output files */
    opf = fopen("cop3502-as1-output-Delvalle-Jared.txt", "w");
    ipf = fopen("cop3502-as1-input.txt", "r");

    /* Clean input data for any non-blank spaces */
    while(get_next_nonblank_line(ipf, buf, 255))
    {
       // fprintf(opf,"%s\n",buf); // This Works
        printf("%s\n", buf);

    }

    /* Close input and output files */
    fclose(opf);
    fclose(ipf);

    return 0;
}
