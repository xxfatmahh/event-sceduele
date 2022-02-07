#include <iostream>
#include <ctime>
#include<fstream>
#include<string> 
#include <list>
#include<vector>
using namespace std;
vector<event>done,upcoming,upcoming_with;
int num_choose=0, num = 0, counter = 0,day,month,year,t_today;
char answer = 0;
class event
{
public:
	class date
{
public:    
	int day;
	int month;
	int year;
};
	string name;
	string place;
	date startdate;
	date enddate;
	int t_start;
	int t_end;
	event() {
		head = tail = NULL;
		counter = 0;
	}
	event* next;
	event* head;
	event* tail;
	event* cur=head;
	event* prev=head;
void displaylogo()//this is function is not important its just to give as good look
{
	system("cls");
	cout << "				   ***********************************        \n";
	cout << "                     *                                 *\n                        *    WELCOME TO Hotel Profile   *\n                        *                                 *\n";
	cout << "			        ***********************************       \n";
}
void MainMenu()//it is the frist page wil be visible when use run code  and ask him which process he want to do 
{
	system("cls");
	displaylogo();
	cout << " Main Menu :" << endl;
	cout << " 1. ADD " << endl;
	cout << " 2. Remove " << endl;
	cout << " 3. Update " << endl;
	cout << "4.display all event " << endl;
	while (true)
	{
		cin >> num_choose;
		if (num_choose == 1)
			add_event( name,  place,startdate.day,startdate.month,startdate.year,enddate.day,enddate.month,enddate.year, t_start,t_end);
		else if (num_choose == 2)
			remove_event( name );
		else if (num_choose == 3)
			update_event( name,  place, startdate.day,startdate.month, startdate.year,  enddate.day,  enddate.month, enddate.year);
		else if (num_choose == 4)
			display_evnt(year,month,day,t_today);
		else
		{
			cout << " Error .. Please Try Again " << endl;
			continue;
		}
	}
}
void add_event(string name, string place,int t_start,int t_end, int s_day, int s_month,int s_year , int e_day,int e_month ,int e_year ){
	while (true) {
		displaylogo();
		ofstream out("New Text Document.text");//this is belongs to file
		event* newevent = new event();
		date* startdate = new date();
		date* enddate = new date();
		cout << "please Enter Event Name \n";
		cin >> name;
		cout << "please Enter the place of Event \n";
		cin >> place;
		//validation_start(s_day,s_month,s_year);
		//t_start = s_year * 10000 + s_month * 100 + s_day;
		//validation_end(e_day, e_month, e_year);	
		//t_end = (e_year * 10000) + (e_month * 100) + e_day;
		//cout << "is for test";
		end_is_after_start(t_start, t_end, s_day,  s_month, s_year, e_day,  e_month,  e_year);
		cout << "sdavf";
		if (counter == 0)
		{
			head = tail = newevent;
			newevent->next = NULL;
			newevent->name = name;
			newevent->place = place;
			startdate->day = s_day;
			startdate->month = s_month;
			startdate->year = s_year;
			enddate->day = e_day;
			enddate->month = e_month;
			enddate->year = e_year;
			counter++;
		}
		else if(counter != 0)
		{
			if (search_collapsing(place, s_day, s_month, s_year, e_day, e_month, e_year)) 
			{
				tail->next = newevent;
				tail = newevent;
				newevent->next = NULL;
				newevent->name = name;
				newevent->place = place;
				startdate->day = s_day;
				startdate->month = s_month;
				startdate->year = s_year;
				enddate->day = e_day;
				enddate->month = e_month;
				enddate->year = e_year;
				out << name << " " << place << s_day << s_month << s_year << e_day << e_month << e_year;// ths is belongs to file
				counter++;
			}
			else
			{
				cout << "there are an event in the same place and date\n";
			}

		}
		cout << "......the event is added to events.....\n\n\n";
		cout << " Press (Y) if you want to Add event : \n";
		cout << " Press (N) to Main Menu : \n";
		while (true)
		{
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
				 add_event(name, place, s_day, s_month, s_year, e_day,e_month, e_year ,t_start,t_end);
			else if (answer == 'N' || answer == 'n')
				MainMenu();
			else
			{
				cout << " Invalid .. Please Try Again !" << endl;
				continue;
			}
		}
	}
}
void end_is_after_start(int t_start, int t_end, int s_day, int s_month, int s_year, int e_day, int e_month, int e_year) 
{
	while (true)
	{
		validation_start(s_day, s_month, s_year,t_start);
		t_start = (s_year * 10000) + (s_month * 100) + s_day;
		validation_end(e_day, e_month, e_year,t_end);
		t_end = (e_year * 10000) + (e_month * 100) + e_day;
		if (t_end < t_start)
		{
			cout << " Invalid .. Please Try Again !" << endl;
			continue;
		}
		else if (t_end == t_start) {
			cout << "invalid...please try again !" << endl;
			continue;
		}
		else //if ( t_end > t_start )
		{
			cout << "event is added \n";
			break;
		}
	}
}
void remove_event(string name) {
	while (true) {
		if (counter==0)
		{
			cout << "there aren't any event to remove  \n";
		}
		else { //we will remove the event 

			if (search_exist(name)) //i think that we can use the pointer in search_x in there 
			{
				//event* prev, *cur = head;
				if (head->name == name)
				{
					head = head->next;
					delete cur;
					counter--;
				}
				else
				{
					cur = cur->next;
					while (cur != NULL && cur->name != name)
					{
						prev = cur;
						cur = cur->next;
					}
					prev->next = cur->next;
					delete cur;
					if (tail == cur)
					{
						tail = prev;

					}
					counter--;
				}
				cout << "\n..................the event is removed.............\n";
			}
			else
				cout << " there aren't any event has this name";
		}
		cout << " Press (Y) if you want to remove event : \n";
		cout << " Press (N) to Main Menu : \n";
		while (true)
		{
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
				remove_event(name);
			else if (answer == 'N' || answer == 'n')
				MainMenu();
			else
			{
				cout << " Invalid .. Please Try Again !" << endl;
				continue;
			}
		}
	}
}
void update_event(string name,string place,int s_day, int s_month, int s_year, int e_day, int e_month, int e_year)
{
	while (true) {
		if (counter==0 )
		{
			cout << "there aren't any event to update\n";
		}
		else {
			if (search_exist(name))
			{
				event* temp = head;
				while (temp->name != name && temp->next != NULL)
				{
					temp = temp->next;
				}
				cout << "which of this you want to update\n";
				cout << "1:" << temp->name << endl << "2:" << temp->place << endl << "3:" << temp->startdate.month << "/" << temp->startdate.day << "/" << temp->startdate.year << endl << "4:" << temp->enddate.month << "/" << temp->enddate.day << "/" << temp->enddate.year << endl;
				cin >> num;
				if (num == 1)
					cin >> temp->name;
				else if (num == 2)
					cin >> temp->place;
				else if (num == 3) {
					validation_start(s_day, s_month, s_year,t_start);
					temp->startdate.day = s_day;
					temp->startdate.month = s_month;
					temp->startdate.year = s_year;
				}
				else if (num == 4) {
					validation_end(e_day, e_month, e_year,t_end);
				}
				end_is_after_start(t_start,t_end,s_day, s_month, s_year, e_day, e_month, e_year);
			}

			else
				cout << "!.......there aren't event has this name \n";
		}
		cout << " Press (Y) if you want to Add event : \n";
		cout << " Press (N) to Main Menu : \n";
		while (true)
		{
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
				update_event(name, place, s_day, s_month, s_year, e_day, e_month, e_year);
			else if (answer == 'N' || answer == 'n')
				MainMenu();
			else
			{
				cout << " Invalid .. Please Try Again !" << endl;
				continue;
			}
		}
	}
}
bool search_exist(string name) {
	bool flag = false;
	cout << "please enter the name of event \n";
	cin >> name;
	event* temp = head;
	for (int i = 0; i < counter; i++)
	{
		if ( temp->name==name)
		{
			flag=true;
			break;
		}
		else if ( temp->name !=name)
		{
			flag = false;
			temp = temp->next;
			continue;
		}
	}
	if (flag)
		return true;
	else
		return false;
}
void display_evnt(int year, int month, int day,int t_today) {
	displaylogo();
	cout << "DISPLAY Menu :" << endl;
	cout << " 1.display_done" << endl;
	cout << " 1.display_upcoming" << endl;
	while (true) {
		cin >> num;
		if (num==1)
		display_done();
		else if(num==2)
		display_upcoming();
		else
		{
			cout << " Error .. Please Try Again " << endl;
			continue;
		}
	}
}
void display_upcoming() {
	cout << "DISPLAY_UPCOMING_Menu :" << endl;
	cout << " 1.display_upcoming_with_start_date" << endl;
	cout << " 1.display_upcoming_with_place" << endl;
	while (true) {
		cin >> num;
		if (num == 1)
			display_upcoming_start();
		else if (num == 2)
			display_upcoming_place();
		else
		{
			cout << " Error .. Please Try Again " << endl;
			continue;
		}
	}
}
bool search_is_colapsing(string place,int t_start,int t_end){
	event* cur = head;
	bool flag = false;
	for (int i = 0; i < counter; i++) {
		
		//t_end = cur->enddate.year * 10000 + cur->enddate.month + 100 + cur->enddate.day;
		if (place == cur->place)
		{
			if (t_start == cur->t_start)
				flag = false;
			else if (t_start < cur->t_start)
			{
				if (t_end < cur->t_start)
					flag = true;
				else if (t_end >= cur->t_start)
					flag = false;
			}
			else if (t_start > cur->t_start) {
				if (t_start > cur->t_end)
					flag = true;
				else if (t_start <= cur->t_end)
					flag = false;
			}
		}
		else
		{		flag = true;
		}
		cur = cur->next;
	}
	return flag;
}
bool search_collapsing(string place ,int s_day,int s_month,int s_year,int e_day,int e_month,int e_year) {
		event* cur = head;
		bool flag = false;
		for (int i = 0; i < counter;i++) {
			if (cur->place == place)
			{
				if (cur->startdate.year == s_year)
				{
					if (cur->startdate.month == s_month)
					{
						if (cur->startdate.day < s_day)
						{
							if (cur->enddate.day > s_day)
							{
								flag = false;
							}
							else if (cur->enddate.day < s_day)
							{
								flag = true;
							}
						}
						else if (cur->startdate.day == s_day)
						{
							flag = false;
						}
						else if (cur->enddate.day == s_day)
						{
							flag = false;
						}
						else if (cur->startdate.day > s_day)
						{
							if (cur->startdate.day > e_day)
								flag = true;
							else if (cur->startdate.day < e_day)
								flag = false;
						}
					}
					else if (cur->startdate.month > s_month)
					{
						if (cur->enddate.month > s_month)
							flag = true;
						else if (cur->startdate.month < e_month)
							flag = false;
					}
					else if (cur->startdate.month < s_month) {
						if (cur->enddate.month < s_month)
							flag = true;
						else if (cur->enddate.month > e_month) {
							flag = false;
						}
					}
				}
				else if (cur->startdate.year > s_year)
				{
					if (cur->startdate.year > e_year)
						flag = true;
					else if (cur->startdate.year < e_year)
						flag = false;
				}

				else if (cur->startdate.year < s_year) {
					if (cur->enddate.year < s_year)
						flag = true;
					else if (cur->enddate.year < s_year)
						flag = false;
				}
			}
			else if (cur->place != place)
			{
				flag = true;
			}
			cur = cur->next;// we forgeted to write 
		}
		return flag;
	}
	void end_after_start(int s_day, int s_month, int s_year, int e_day, int e_month, int e_year) {
		while (true) {
			if (e_year > s_year) {
				break;
			}
			else if (e_year == s_year)
			{
				if (e_month > s_month) {
					break;
				}
				else if (e_month = s_month)
				{
					if (e_day == s_day)//if the event is end in the same day
					{
						cout << " Invalid Date .. Please Try Again ! " << endl << "enter the end day:";
						cin >> e_day;
						continue;
					}
					else if (e_day < s_day)
					{
						cout << " Invalid Date .. Please Try Again ! " << endl << "please enter the end day";
						cin >> e_day;
						continue;
					}
					else if (e_day > s_day) {
						break;
					}
				}
				else if (e_month < s_month)
				{
					cout << " Invalid Date .. Please Try Again ! " << endl << "please enter the end month";
					cin >> e_month;
					continue;
				}
			}
			else if (e_year < s_year)
			{
				cout << " Invalid Date .. Please Try Again ! " << endl << "please enter the end year";
				cin >> e_year;
				continue;
			}
		}
	}
	void validation_start(int s_day,int s_month ,int s_year,int t_start) {
		while (true) {
			cout << "please Enter the day of start date \n";
			cin >> s_day;
			if (s_day > 31 || s_day < 0)
			{
				cout << " Invalid Date .. Please Try Again ! " << endl;
				continue;
			}
			else
				break;
		}
		cout << "please Enter the month of start date \n";
		while (true)
		{
			cin >> s_month;
			if (s_month > 12 || s_month < 0)
			{
				cout << " Invalid Date .. Please Try Again ! " << endl;
				continue;
			}
			else
				break;
		}
		cout << "please Enter the year of start date \n";
		while (true)
		{
			cin >> s_year;
			if (s_year > 2100 || s_year <2000)
			{
				cout << " Invalid Date .. Please Try Again ! " << endl;
				continue;
			}
			else
				break;
		}
	}
	void validation_end(int e_day, int e_month, int e_year,int t_end)
	{
		cout << "please Enter the day of End date \n";
		while (true) {
			cin >> e_day;
			if (e_day > 31 || e_day < 0)
			{
				cout << " Invalid Date .. Please Try Again ! " << endl;
				continue;
			}
			else
				break;
		}
		cout << "please Enter the month of End date \n";
		while (true)
		{
			cin >> e_month;
			if (e_month > 12 || e_month < 0)
			{
				cout << " Invalid Date .. Please Try Again ! " << endl;
				continue;
			}
			else
				break;
		}
		cout << " please Enter the year of End date\n";
		while (true)
		{
			cin >> e_year;
			if (e_year > 2100 || e_year < 2000)
			{
				cout << " Invalid Date .. Please Try Again ! " << endl;
				continue;
			}
			else
				break;
		}

	}
	void display_done() {
		search_done(year, month, day, t_today);
		for (int i = 0; i < done.size(); i++) {
			cout << i + 1 << "DONE EVENT :" << endl;
			cout << done[i]<<endl;
		}
	
	}
	void display_upcoming_start() {
		search_done(year, month, day, t_today);
		for (int i = 0; i < upcoming.size(); i++) {
		
			 upcoming[i] << endl;
		}
	}
	void display_upcoming_place() {

	}void getTime(int year, int month, int day, int& t_today) {
		time_t t = time(0);   // get time now
		struct tm now;
		localtime_s(&now, &t);
		year = now.tm_year + 1900;
		month = now.tm_mon + 1;
		day = now.tm_mday;
		t_today = year * 10000 + month * 100 + day;
		cout << t_today;
	}
	void search_done(int year,int month,int day,int t_today) {
		//vector<event>n;
		getTime(year, month, day, t_today);
		/*list<int>::iterator it = l.begin();
		for (it = l.begin(); it != l.end(); it++)
			cout << *it << endl;*/
		event* tmp = head;
		event v;
		for (int i = 0; i < counter; i++)//while(tmp!=NULL)
		{
			v.name = tmp->name;     //this event is done 
			v.place = tmp->place;
			v.startdate.day = tmp->startdate.day;
			v.startdate.month = tmp->startdate.month;
			v.startdate.year = tmp->startdate.year;
			v.enddate.day = tmp->enddate.day;
			v.enddate.month = tmp->enddate.month;
			v.enddate.year = tmp->enddate.year;
			if (t_end < t_today)
			{
				done.push_back(v);
			}
			else if (t_end >= t_today)
			{
				upcoming.push_back(v); //event is upcoming
			}
			tmp = tmp->next;
		}
	}
};
int main() {
		event l;		
		l.MainMenu();
		return 0;
}

	// i think that any error will appear will happen because calling function






