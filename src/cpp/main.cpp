#include <stdio.h>
#include <stdlib.h>

#include "rps.hpp"

int main(int argc, char* args[]) {
	if (argc != 3) {
		fprintf(stderr, "Please provide choices for player one and player two as arguments\n");
		return 1;
	}

	const RPSItem* p1, *p2;

	p1 = rps_item_by_name(args[1]);
	if (p1 == 0) {
		fprintf(stderr, "P1 INVALID\n");
		return 1;
	}
	p2 = rps_item_by_name(args[2]);
	if (p2 == 0) {
		fprintf(stderr, "P2 INVALID\n");
		return 2;
	}

	int rval = 0;
	switch(rps_match(p1, p2)) {
	case RPS_TIE: {
		printf("TIE\n");
		break;
	}
	case RPS_P1_WINS: {
		printf("P1 WINS\n");
		p2->say_you_lost(stderr);
		break;
	}
	case RPS_P2_WINS: {
		printf("P2 WINS\n");
		p1->say_you_lost(stderr);
		break;
	}
	case RPS_ERROR: {
		fprintf(stderr, "ERROR");
		rval = 255;
	}
	}

	return rval;
}
