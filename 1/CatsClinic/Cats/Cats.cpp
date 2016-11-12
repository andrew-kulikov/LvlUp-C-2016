#include <iostream>
#include <stdio.h>

#define CLINIC_SIZE 100
#define NAME_SIZE 20

using namespace std;

struct Cat {
	int index;
	char name[NAME_SIZE];
	int nameLen;
	int age;
	int weight;
	char language[NAME_SIZE];
	int langLen;
	int nya;
	int hunger;
	bool doesLoveYou;
	bool isAlive;
};

int display(Cat *cats) {
	int count;
	count = 0;
	for (int i = 0; i < CLINIC_SIZE; i++) {
		if (cats[i].isAlive) {
			count++;
		}
	}
	return count;
}
void add(Cat *cats) {
	char newName[NAME_SIZE], language[NAME_SIZE];
	bool doesLoveYou;
	int newWeight, newNya, newHunger;
	newWeight = 0;
	newNya = 0;
	newHunger = 0;
	if (display(cats) == CLINIC_SIZE) {
		cout << "We can't add new cat";
	}
	else {
		for (int i = 0; i < CLINIC_SIZE; i++) {
			if (cats[i].isAlive == 0) {
				printf("Type name of your cat: ");
				scanf("%s", newName);
				cats[i].nameLen = strlen(newName);
				for (int j = 0; j < strlen(newName); j++) {
					cats[i].name[j] = newName[j];
				}
				cout << "Type weight of your cat : ";
				cin >> newWeight;
				cats[i].weight = newWeight;
				cout << "Type nya of your cat: ";
				cin >> newNya;
				cats[i].nya = newNya;
				cout << "Type hunger of your cat: ";
				cin >> newHunger;
				cats[i].hunger = newHunger;
				cout << "Type language of your cat: ";
				scanf("%s", language);
				cats[i].langLen = strlen(language);
				for (int j = 0; j < strlen(language); j++) {
					cats[i].language[j] = language[j];
				}
				cout << "Does new cat love you?(1/0) ";
				cin >> doesLoveYou;
				cats[i].doesLoveYou = doesLoveYou;
				cats[i].isAlive = 1;
				printf("Cat %s was added!\n", newName);
				break;
			}
		}
	}
}

void changeByIndex(Cat *cats) {
	char newName[NAME_SIZE], language[NAME_SIZE];
	bool doesLoveYou;
	int newWeight, newNya, newHunger, index;
	cout << "What is cat's index? ";
	cin >> index;
	for (int i = 0; i < CLINIC_SIZE; i++) {
		if (i == index) {
			printf("Type new name of your cat: ");
			scanf("%s", newName);
			cats[i].nameLen = strlen(newName);
			for (int j = 0; j < strlen(newName); j++) {
				cats[i].name[j] = newName[j];
			}
			cout << "Type new weight of your cat : ";
			cin >> newWeight;
			cats[i].weight = newWeight;
			cout << "Type new nya of your cat: ";
			cin >> newNya;
			cats[i].nya = newNya;
			cout << "Type new hunger of your cat: ";
			cin >> newHunger;
			cats[i].hunger = newHunger;
			cout << "Type new language of your cat: ";
			scanf("%s", language);
			cats[i].langLen = strlen(language);
			for (int j = 0; j < strlen(language); j++) {
				cats[i].language[j] = language[j];
			}
			cout << "Does new cat love you?(1/0) ";
			cin >> doesLoveYou;
			cats[i].doesLoveYou = doesLoveYou;
			cats[i].isAlive = 1;
			printf("Cat %s was changed!\n", newName);
			break;
		}
	}
}
void kill(Cat *cats) {
	int index;
	cout << "What cat do you want to kill? ";
	cin >> index;
	if (index < CLINIC_SIZE) {
		cats[index].isAlive = 0;
		cout << "Cat " << cats[index].name << " was killed" << endl;
	}
	else
		cout << "We can't kill this cat" << endl;
}
void showAll(Cat *cats) {
	int count = 0;
	for (int i = 0; i < CLINIC_SIZE; i++) {
		if (cats[i].isAlive) {
			cout << count + 1 << endl << "Name: ";
			for (int j = 0; j < cats[i].nameLen; j++) {
				cout << cats[i].name[j];
			}
			printf("\nWeight: %d\nNya: %d\nHunger: %d\nLanguage: ", cats[i].weight, cats[i].nya, cats[i].hunger);
			for (int j = 0; j < cats[i].langLen; j++) {
				cout << cats[i].language[j];
			}
			printf("\nDoes love you: %d\n", cats[i].doesLoveYou);
			count++;
		}
	}
}
void Exit(Cat *cats) {
	cout << "End of the programm!" << endl;
	exit(0);
}

int main() {
	int switcher;
	switcher = 0;
	Cat cats[CLINIC_SIZE];
	for (int i = 0; i < CLINIC_SIZE; i++) {
		cats[i].isAlive = 0;
		cats[i].index = i;
	}

	while (switcher != 6) {
		cout << "Type \n1)Display number of cats; \n2)Add cat \n";
		cout << "3)Change cat by index \n4)Kill cat \n5)Show all cats \n6)Exit\n";
		cin >> switcher;
		switch (switcher)
		{
		case 1: {
			int count = display(cats);
			printf("Number of cats is: %d\n", count);
			break;
		}
		case 2: {
			add(cats);
			break;
		}
		case 3: {
			changeByIndex(cats);
			break;
		}
		case 4: {
			kill(cats);
			break;
		}
		case 5: {
			showAll(cats);
			break;
		}
		case 6: {
			Exit(cats);
			break;
		}
		default:
			break;
		}
	}
	return 0;
}