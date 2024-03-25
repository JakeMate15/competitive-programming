#include <stdio.h>
#include <bits/stdc++.h>
#define MAX_BOLTS 500
#define MAX_NUTS  500

/* global copy of the input data */
int nuts,bolts;
int fits[MAX_BOLTS][MAX_NUTS];
int bolt_difficulty[MAX_BOLTS];

typedef struct {
    int index;
    int difficulty;
} Bolt;

Bolt bolt_order[MAX_BOLTS];
int compareBolts(const void* a, const void* b) {
    Bolt* boltA = (Bolt*) a;
    Bolt* boltB = (Bolt*) b;
    return boltA->difficulty - boltB->difficulty;
}

void read_input_data(void) {
    int n, b;
    scanf("%d%d", &bolts, &nuts);
    for (b = 0; b < bolts; b++) {
        bolt_order[b].index = b;
        bolt_order[b].difficulty = 0;
        for (n = 0; n < nuts; n++) {
            scanf("%d", &fits[b][n]);
            if (fits[b][n]) bolt_order[b].difficulty++;
        }
    }
}
/* data used to match nuts with bolts */
int nut_used[MAX_NUTS];
int bestmatched;
void init_match(void) {
    bestmatched = 0;
    for (int n = 0; n < nuts; n++) nut_used[n] = 0;
    qsort(bolt_order, bolts, sizeof(Bolt), compareBolts);
}

void match_bolt(int boltno, int matched) {
    int n;
    if (boltno == bolts) {
        if (matched > bestmatched) bestmatched = matched;
        return;
    }

    int boltIndex = bolt_order[boltno].index;
    
    // Intenta no emparejar este tornillo.
    match_bolt(boltno + 1, matched);

    // Intenta emparejar con todas las tuercas que encajen y no se hayan usado.
    for (n = 0; n < nuts; n++) {
        if (!nut_used[n] && fits[boltIndex][n]) {
            nut_used[n] = 1;
            match_bolt(boltno + 1, matched + 1);
            nut_used[n] = 0;
        }
    }
}z

int main(){
    int cases,caseno;
    scanf("%d",&cases);
    for(caseno=1;caseno<=cases;caseno++){
        read_input_data();
        init_match();
        match_bolt(0,0);
        printf("Case %d: ",caseno);
        printf("a maximum of %d nuts and bolts ",bestmatched);
        printf("can be fitted together\n");
    }
    return 0;
}