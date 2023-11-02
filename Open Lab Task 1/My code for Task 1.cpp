#include<iostream>
#include<string>

using namespace std;
// i couldnt learn <ctime> library in this short period
// this program only work with full potential with <ctime> library but i have built the logic.
int main()
{
	int book_counter = 0, day_limit = 30;
	char garbage;
	int cont, day, month, year;
	string user_name, book_name, book_namec;
	bool check = false;
	cout << "To Access our Library System: \nEnter Your Name:";
	getline(cin, user_name);


	while (check == false)
	{
		cout << "Enter Current Date (format: dd/mm/yy) = ";
		cin >> day >> garbage >> month >> garbage >> year;

		string book_issuedate;
		int todaydate = day + (month * 30);
		int duedate = 30 + todaydate;

		cout << "\n\nBAHRIA LIBRARY SYSTEM\n\n";
		cout << "-------Welcome-------";        // user interface
		cout << "\n\n > Books\n";
		cout << "      > Borrow (0)" << "\n      > Return (1)";
		cout << "\n\n > Quit (2)";
		cout << "\n\nPlease Enter Your Choice: ";
		int choice;
		cin >> choice;
		if (choice == 0)
		{
			cout << "\nBorrow Section";
			cout << "\nNotice Board :  ";
			cout << "\n                > Book can only be borrowed for 30 days only";
			cout << "\n                > After that book need to be returned or re-borrowed";
			cout << "\n                > Student can issue only 1 book at a time";
			cout << "\n\nBook Borrowed = " << book_counter;
			if (book_counter <= 1)
			{
				cout << "\nType book name to issue (lowercase only) : ";      //book issuance
				cin.ignore();
				getline(cin, book_name);
				string book_issuedate = to_string(day) + " - " + to_string(month) + " - " + to_string(year);
				cout << "\nThe Book \"" << book_name << "\" has been issued to " << user_name << endl;
				book_counter++;
			}
		}
		else if (choice == 1)
		{
			cout << "\nReturn Section";
			if (book_counter != 0)
			{
				cout << "\nType Name of the Book You Want to Return (lowercase only) : ";
				cin >> book_namec;
				cout << "Book Issuance Date : " << book_issuedate;
				cout << "\nThanks for returning";
				// logic for printing fine
				if (todaydate > duedate)
				{
					int fine = (todaydate - duedate) * 1;
					cout << "\nYou have passed the due date\nYour Fine : " << fine;
				}
				else "Returned in time";
			}
			else
			{
				cout << "You don't have any books to return";
			}
		}
		else if (choice == 2)
		{
			return 0;
		}
		else
		{
			cout << "You Entered A Wrong Choice\n\n";
			check = false;
		}
	}
	return 0;
}