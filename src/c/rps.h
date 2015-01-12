
typedef enum {RPS_P1_WINS,
			  RPS_P2_WINS,
			  RPS_TIE,
			  RPS_ERROR} RPS_Result;

typedef struct {
	const char* name;
	const int   id;
} RPSItem;

RPSItem* rps_item_by_name(const char* name);
RPS_Result rps_match(const RPSItem* p1_pick, const RPSItem* p2_pick);
