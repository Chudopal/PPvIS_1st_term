#include "bank.h"

vector<cart>read::read_cart(string file) { 

	vector<cart> carte;
	int i = 0;
	ifstream fin(file);
	if (fin.is_open())
		while (!fin.eof()) {
			carte.resize(i + 1);
			fin >> carte[i].id;
			fin >> carte[i].name;
			fin >> carte[i].pin;
			fin >> carte[i].cash;
			fin >> carte[i].date;
			i++;
		}
	return carte;
}
vector<base>read::read_base(string file) {
	vector<base> bas;
	int i = 0;
	ifstream fin(file);
	while (!fin.eof())
	{
		bas.resize(i + 1);
		fin >> bas[i].id_base;
		i++;
	}
	return bas;
}

main_windows::main_windows(vector<cart> cart , vector<base>bas = {}) {
	carte = cart;
	this->bas = bas;
}
int main_windows::print() {
	double i;
	cout << "Âűáĺđĺňĺ îďĺđŕöčţ:"<<endl;
	cout << "1-Ďđîâĺđęŕ ń÷ĺňŕ\t\t2-Ńí˙ňčĺ íŕëč÷íűő\n3-Ďîëîćčňü äĺíüăč íŕ ń÷ĺň\t4-Ďĺđĺâîä ń ęŕđňű íŕ ęŕđňó\n5-Čçěĺíĺíčĺ PIN\t\t\t6-Číôîđěŕöč˙ î ń÷ĺňĺ\n";
	cout << "7-ďîěĺí˙ňü đŕáî÷óţ ęŕđňó\t8-âűőîä\n";
	cin >> i;
	return i;
}
void main_windows::card_choose() {
	double card_number;
	do {
		cout << "âűáĺđčňĺ ęŕđňó äë˙ đŕáîňű:" << endl;
		for (int i = 0; i < bas.size(); i++) {
			cout << i + 1 << ") " << bas[i].id_base << endl;
		}
		cin >> card_number;
	} while (card_number > bas.size() || card_number <= 0);
	value= card_number - 1;
}
bool main_windows::continu() {
	double k;
	cout << "Ćĺëŕĺňĺ ďđîäîëćčňü?\n1-äŕ\t2-íĺň\n";
	cin >> k;
	if (k == 2) {
		return false;
	}
	return true;
}

bool check_pin::checkpin() {
	string pas; int i = 0;
	cout << "Ââĺäčňĺ PIN:";
	cin >> pas;
	do {
		if (pas == carte[value].pin)
			return true;
		i++;
		cout << "Ďîâňîđčňĺ ââîä:";
		cin >> pas;
	} while (i < 2);
	return false;
}
check_pin::check_pin(main_windows wind ) {
	this->carte = wind.carte;
	value = wind.value;
}

check::check(main_windows wind) {
	this->carte = wind.carte;   
	value = wind.value;
}
double  check::check_the_balance() {
		return carte[value].cash;
}

pull::pull(main_windows wind) {
	this->carte = wind.carte;
	value = wind.value;
}
double pull::pull_cash() {
	double amo;
		cout << endl << "Ââĺäčňĺ ńóěěó:";
		cin >> amo;
		if (amo <= carte[value].cash) {
			carte[value].cash -= amo;
			return amo;
		}
		else cout << "Íĺäîńňŕňî÷íî ńđĺäńňâ" << endl;

	return 0;
}

put::put(main_windows wind) {
	this->carte = wind.carte;
	value = wind.value;
}
void put::put_money_in_the_account() {
	cout << "Ââĺäčňĺ ńóěěó:" << endl;
	double money;
	cin >> money;
	carte[value].cash += money;
	cout << "Çŕâĺđřĺíî óńďĺříî"<<endl;
}

trans::trans(main_windows wind) {
	this->carte = wind.carte;
	this->bas = wind.bas;
	value = wind.value;
}
void trans::transfer() {
	cout << "Äîńňóďíűĺ ęŕđňű:" << endl;
	for (int i = 0; i < carte.size(); i++) {
		cout << carte[i].id << endl;
	}
	string id_new;
	cout << "Ââĺäčňĺ íîěĺđ ęŕđňű ďîëó÷ŕňĺë˙: ";
	cin >> id_new;
	double number;
	for (int i = 0; i < bas.size(); i++) {
		if (bas[i].id_base == id_new && id_new!=bas[value].id_base)
		{
			number = i;
			break;
		}
		if (i == bas.size() - 1) {
			cout << "Íĺâĺđíűé ââîä" << endl;
		}
	}
	double sum;
		cout << endl << "ââĺäčňĺ ńóěěó:";
		cin >> sum;
		if (sum <= carte[value].cash) {
			carte[number].cash += sum;
			carte[value].cash-= sum;
			cout << "óńďĺříî çŕâĺđřĺíî"<<endl;
			
		}
		else cout << "íĺäîńňŕňî÷íî ńđĺäńňâ" << endl;
		

}

change::change(main_windows wind) {
	this->carte = wind.carte;
	this->bas = wind.bas;
	value = wind.value;
}
void change::change_pin() 
{
	string pin_old, pin_new;
	cout << "Ââĺäčňĺ ńňŕđűé ďŕđîëü:";
	cin >> pin_old;
	if (pin_old == carte[value].pin)
	{
		cout << endl << "Ââĺäčňĺ íîâűé ďŕîëü:";
		cin >> pin_new;
		carte[value].pin = pin_new;
		cout << "çŕâĺđřĺíî" << endl;
		

	}
	else cout << "íĺâĺđíűé ďŕđîëü" << endl;

}

info::info(main_windows wind) {
	this->carte = wind.carte;
	value = wind.value;
}
void info::out(){
	cout << "Âëŕäĺëĺö ęŕđňű: " <<carte[value].name<<endl;
	cout << "Ńđîę äĺéńňâč˙ ęŕđňű: " << carte[value].date << endl;

}

session::session(vector<cart>c, vector<base>b) {
	car = c;
	bas = b;
}
void session::beg() {
	int i = 0;
	double k;
	main_windows win(car,bas);
	win.card_choose();
	check_pin pin(win);
		i = 0;
		if (!pin.checkpin()) i = 1;
		system("cls");
		while (!i)
		{	
			switch (win.print())
			{
			case 1: {
				check ch(win);
				cout << "Íŕ âŕřĺě ń÷ĺňĺ: " << ch.check_the_balance() << endl;
				if (!win.continu())
				{
					i = 1;
					break;
				}
				if (!pin.checkpin()) i = 1;
				system("cls");
				break; }
			case 2: { 
				pull p(win);
				p.pull_cash();
				win = p;
				if (!win.continu())
				{
					i = 1;
					break;
				}
				if (!pin.checkpin()) i = 1;
				system("cls");
				break; }
			case 3: {
				put pt(win);
				pt.put_money_in_the_account();
				win = pt;
				if (!win.continu())
				{
					i = -1;
					break;
				}
				if (!pin.checkpin()) i = 1;
				system("cls");
				break; }
			case 4: {
				trans tr(win);
				tr.transfer();
				win = tr;
				if (!win.continu())
				{
					i = -1;
					break;
				}
				if (!pin.checkpin()) i = 1;
				system("cls");
				break; }
			case 5: {
				change ch(win);
				ch.change_pin();
				win = ch;
				if (!win.continu())
				{
					i = -1;
					break;
				}
				if (!pin.checkpin()) i = 1;
				system("cls");
				break;
			}
			case 6: {
				info inf(win);
				inf.out();
				if (!win.continu())
				{
					i = 1;
					break;
				}
				if (!pin.checkpin()) i = 1;
				system("cls");
				break; }
			case 7: {
				win.card_choose();
				system("cls");
				break; }
			case 8: 
			{
				i = 1; 
				break;
			}
			default:
			{
				cout << "ďîâňîđčňĺ ââîä" << endl; break; }
			}
		}
		car = win.carte;
	}


void session::end(string file) {
	ofstream fout(file);
	for (int i = 0; i < car.size(); i++)
	{
		fout << car[i].id<<"\n";
		fout << car[i].name << "\n";
		fout << car[i].pin << "\n";
		fout << car[i].cash << "\n";
		if (i == car.size() - 1)fout << car[i].date;
		else fout << car[i].date << "\n";
	}


}
/*1234567854784568
ivanov
1111
9000
12.20
1234567854780000
petrov
2222
5500
08.20
9876543219876543
sidorov
3333
11000
10.21*/