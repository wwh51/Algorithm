
enum TableType
{
	Small = 0,
	Mediam = 1,
	Large = 2,
	...
	MAX_TYPE = 4,
	
};
class TableCategory
{
	int table_type;
	int num_seats;
}

class Table
{
	bool Reserve(int start, int end);
	bool CancelReservation(int start);
private:
	int id;
	int table_type;
	
	vector< pair<int, int> > occupied_timerange_today;
};

class Request
{
	string customer_name;
//	string phone_number;	
};

class ReserveRequest: public Request
{
	int num_customes;
	int start;
	int end;
};

class CancelRequest: public Request
{
	
};

class Reservation
{
	string customer_name;
	vector<int> table_id;
	int start;	
};


class Table
class RestaurantReservationSystem
{
public:
	InitSystem()
	{
		table_cat.push_back(...);
		tables.push_back(...);
		map_id_table[] = ;
	}
	
	ResetStartOfDay()
	{
		map_name_reservation.clear();
	}
	
	bool HandleRequest(Request&);
	
protected:
	bool HandleBookRequest(ReserveRequest& req)
	{
		Reservation reservation(req.customer_name);
		
		int num_customes = req.num_customes;
		//find the smallest table can take them
		match_tc = 0;
		for( tc in table_cat)
		{
			match_tc = table_cat.table_type;
			if tc.num_seats >= num_customes
				break;
		}
		start_tc = match_tc;
		while(num_customes > 0)
		{
			Table* pTable = GetTable(match_tc, req.start, req.end);
			if(pTable != NULL)
			{
				pTable->Reserve(start,end)
				num_customes -= table_cat[match_tc].num_seats;
			}
			else
			{
				match_tc = (match_tc +1) % <MAX_TYPES;
				if(match_tc == start_tc)
				{
					// cancel all reservation
					// return failed 
				}
			}
			
		}
		
		
	}
	
	
private:	
	vector<TableCategory> table_cat; 
	vector< vector<Table*> > tables;
	unordered_map<int, Table*> map_id_table;
	unordered_map<string, Reservation> map_name_reservation;

}
