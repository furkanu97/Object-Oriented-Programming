#include <iostream>
using namespace std;

class Pizza{
public:
	string name, size, ingredients[10], crust_type;
	Pizza();
	Pizza(string x, string y, string z);
	void print() {
		int i;
		for(i=0;i<6;i++) {
			cout << i << ". " << ingredients[i] << endl;
		}
		cout << "Press 0 to save it." << endl;
	}
};

class Order {
public:
	string customer;
	Pizza piz;
	int drink[5] = { 0 };

	Order(string x, Pizza y, int z[]) {
		customer = x;
		piz = y;
		for (int i = 0; i < 5; i++) {
			drink[i] = z[i];
		}
	}

	Order(string x, Pizza y) {
		customer = x;
		piz = y;
	}

	float getPrice(int amount) {
		float check=0;
		string size = piz.size;
		if (size == "small") {
			check += 15;
		}
		else if (size == "medium") {
			check += 20;
		}
		else {
			check += 25;
		}
		check *= amount;
		for (int i = 0; i < 5; i++) {
			switch (drink[i])
			{
				case 1:
					check += 4;
					break;
				case 2:
					check += 2;
					break;
				case 3:
					check += 3;
					break;
				case 4:
					check += 3.5;
					break;
				default:
					break;
			}
		}
		return check;
	}

	void printOrder() {
		string name = piz.name;
		string size = piz.size;
		string crust = piz.crust_type;
		int i;
		cout << "Name: " << customer << endl;
		cout << name << "Pizza(";
		for (i = 0; i < 6; i++) {
			cout << piz.ingredients[i] << " ";
		}
		cout << ")" << endl;
		cout << "size: " << size << "," << "crust: " << crust << endl;
		for (i = 0; i < 5; i++) {
			if (drink[i] == 1) {
				cout << "cola ";
			}
			else if (drink[i] == 2) {
				cout << "soda ";
			}
			else if (drink[i] == 3) {
				cout << "ice tea ";
			}
			else if (drink[i] == 4) {
				cout << "fruit juice ";
			}
			else {

			}
		}
	}
};

Pizza changed(Pizza wp) {
	int removed = -1,i,j;
	string temp;
	cout << "Please enter the numbers of the ingredient you want to remove from your pizza: " << endl;
	for (i = 0; i < 6; i++) {
		cout << i+1 << ". " << wp.ingredients[i] << endl;
	}
	cout << "Press 0 to save it." << endl;
	cin >> removed;
	while (removed != 0) {
		wp.ingredients[removed - 1] = "";
		cin >> removed;
	}
	return wp;
}

Pizza::Pizza() {
	size = "medium";
	ingredients[0] = "mozarella";
	crust_type = "normal";
}

Pizza::Pizza(string x, string y, string z) {
	name = z;
	if (name == "Chicken") {
		size = x;
		crust_type = y;
		ingredients[0] = "mozarella";
		ingredients[1] = "chicken";
		ingredients[2] = "mushroom";
		ingredients[3] = "corn";
		ingredients[4] = "onion";
		ingredients[5] = "tomato";
	}
	else if (name == "Broccoli") {
		size = x;
		crust_type = y;
		ingredients[0] = "mozarella";
		ingredients[1] = "broccoli";
		ingredients[2] = "pepperoni";
		ingredients[3] = "olive";
		ingredients[4] = "corn";
		ingredients[5] = "onion";
	}
	else if (name == "Broccoli") {
		size = x;
		crust_type = y;
		ingredients[0] = "mozarella";
		ingredients[1] = "sausage";
		ingredients[2] = "tomato";
		ingredients[3] = "olive";
		ingredients[4] = "mushroom";
		ingredients[5] = "corn";
	}
	else {
		cout << "We have only 3 types of pizzas: Chicken, Broccoli and Sausage.";
	}
}


int main() {
	Pizza a("small","normal","Chicken");
	cout << "Welcome to Kopernik Pizza!\n"
			"1. Add an order\n"
			"2. List orders\n"
			"3. Deliver order\n"
			"4. Exit\n"
			"Choose what to do: ";
	int ps, aop, dr, ct = 0, sl, drink[5];
	string top, sop, cop, nm ;
	cin >> sl;
	switch (sl) 
	{
		case 1:
			cout << "Welcome to Kopernik Pizza!\n"
				"1. Chicken Pizza (mozarella, chicken, mushroom, corn, olive, onion, tomato\n"
				"2. Broccoli Pizza (mozarella, broccoli, pepperoni, olive, corn, onion\n"
				"3. Sausage Pizza (mozarella, sausage, tomato, olive, mushroom, corn\n"
				"0. Back to main menu" << endl;

			cin >> ps;
			switch (ps)
			{
				case 1:
					top = "Chicken";
					break;
				case 2:
					top = "Broccoli";
					break;
				case 3:
					top = "Sausage";
					break;
				default:
					return 1;
			}
			cout << "Select size: small (15 TL), medium (20 TL), big (25 TL)" << endl;
			cin >> sop;
			cout << "Select crust type: thin, normal, thick" << endl;
			cin >> cop;
			cout << "Enter the amount: ";
			cin >> aop;
			Pizza order(sop, cop, top);
			order = changed(order);
			cout << order.ingredients[0] << order.ingredients[1] << order.ingredients[2] << order.ingredients[3] << order.ingredients[4] << order.ingredients[5] << endl;
			cout << "Please choose a drink:\n"
					"0. no drink\n"
					"1. cola 4 TL\n"
					"2. soda 2 TL\n"
					"3. ice tea 3 TL\n"
					"4. fruit juice 3.5 TL\n"
					"Press -1 for save your order" << endl;
			cin >> dr;
			while (dr != -1) {
				switch (dr)
				{
				case 0:
					drink[ct] = dr;
					break;
				case 1:
					drink[ct] = dr;
					break;
				case 2:
					drink[ct] = dr;
					break;
				case 3:
					drink[ct] = dr;
					break;
				default:
					break;
				}
				cin >> dr;
				ct++;
			}
			cout << "Please enter your name: ";
			cin >> nm;
			if (ct == 0) {
				Order ord(nm, order);
			}
			else {
				Order ord(nm, order, drink);
			}
			cout << "Your order is saved, it will be delivered when it is ready..\n"
				"------------------\n"
				"Name: " + nm;
	}
	return 0;
}