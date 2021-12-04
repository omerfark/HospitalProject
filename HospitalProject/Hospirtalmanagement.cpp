#include <string>
#include <iostream>
#include <vector>



using namespace std;

void WelcomeScreen();
void PatientProcces();
void Doctorprocces();
void RoomProcces();
void Patientobject();
void Doctorobject();
void AllRoomNum();
void printPatientInf();
void PrintPatientRoom();
void showPatientDisease();
void AddPatient();
void AddDoctor();
void printDoctorInf();
void PrintDoctorRoom();
void ShowDoctorSalary();



//------------------Patient Class---------------//

class PatientClass {
public:
	string Pname;
	int Page;
	int Pid;
	string PDisease;
	int PRoomnum;

	PatientClass(string Pname, int Page, int Pid, string PDisease, int PRoomnum);


	void printPatientInf() {
		cout << "- - - - - - - - - - - " << endl;
		cout << "Patient Name: " << Pname << endl;
		cout << "Patient Age: " << Page << endl;
		cout << "Patient Id: " << Pid << endl;
		cout << "Patient Disease: " << PDisease << endl;
		cout << "Patient Room Number:  " << PRoomnum << endl;
		cout << "- - - - - - - - - - - " << endl;

	}

	void PrintPatientRoom() {
		cout << "Patient Name : " << Pname;
		cout << " -- Patient Room Number is : " << PRoomnum << endl;
	}

	void showPatientDisease() {
		cout << "Patient Name:  " << Pname << " - Patieent Disease: " << PDisease << endl;
	}
};

vector<PatientClass> patientList;


PatientClass::PatientClass(string Pname, int Page, int Pid, string PDisease, int PRoomnum) {
	this->Pname = Pname;
	this->Page = Page;
	this->Pid = Pid;
	this->PDisease = PDisease;
	this->PRoomnum = PRoomnum;
	patientList.push_back(*this);
}

void AddPatient() {


	string Name;
	int Age;
	int Id;
	string Disease;
	int roomnum;

	cout << "Name: ";
	cin >> Name;
	cout << "Age:  ";
	cin >> Age;
	cout << "Id: ";
	cin >> Id;
	cout << "Disease: ";
	cin >> Disease;
	cout << "Room number: ";
	cin >> roomnum;

	PatientClass newPatient2(Name, Age, Id, Disease, roomnum);

}


//------------------Doctor Class---------------//

class DoctorClass {
public:
	string DName;
	int DAge;
	int DId;
	double DSalary;
	int  DRoomnum;

	DoctorClass(string DName, int DAge, int DId, double DSalary, int DRoomnum);


	void printDoctorInf() {
		cout << "- - - - - - - - - - - " << endl;
		cout << "Doctor Name: " << DName << endl;
		cout << "Doctor Age: " << DAge << endl;
		cout << "Doctor Id: " << DId << endl;
		cout << "Doctor Salary: " << DSalary << endl;
		cout << "Doctor Room Number:  " << DRoomnum << endl;
		cout << "- - - - - - - - - - - " << endl;

	}

	void PrintDoctorRoom(){
		cout << "Doctor Name : " << DName;
		cout << " -- Doctor Room Number is : " << DRoomnum <<  endl;
	}

	void AllRoomNum() {
		cout << "Avaliable Room Number:   " << DRoomnum << endl;
	}
	
	void ShowDoctorSalary() {
		cout << "Doctor " << DName << " salary is " << DSalary << endl;
	}
};

vector<DoctorClass> DoctorList;

DoctorClass::DoctorClass(string DName, int DAge, int DId, double DSalary, int DRoomnum) {
	this->DName = DName;
	this->DAge = DAge;
	this->DId = DId;
	this->DSalary = DSalary;
	this->DRoomnum = DRoomnum;
	DoctorList.push_back(*this);

}

void AddDoctor() {

	string DocName;
	int DocAge;
	int DocId;
	double DocSalary;
	int Docroomnum;

	cout << "Name: ";
	cin >> DocName;
	cout << "Age:  ";
	cin >> DocAge;
	cout << "Id: ";
	cin >> DocId;
	cout << "Salary: ";
	cin >> DocSalary;
	cout << "Room number: ";
	cin >> Docroomnum;

	DoctorClass newDoctor(DocName, DocAge, DocId, DocSalary, Docroomnum);

	
}

int main() {
	
	DoctorClass doctor1("Ferhat", 29, 123, 20500, 1);
	DoctorClass doctor2("Ayse", 32, 456, 25500, 2);
	PatientClass patient1("ahmet", 45, 111, "Heart", 1);
	PatientClass patient2("omer", 54, 112, "respiratory", 2);

	WelcomeScreen();
	
	return 0;
}	

//-------Welcome Screen---------//

void WelcomeScreen() {
	cout << "*****   Hospital Manager Sistem   ******" << endl;
	cout << "       -------------------------     " << endl;

	int SelectProcces;
	cout << "SELECT: " << endl << "1. Show Patient Procces " << endl << "2. Show Doctor Procces" << endl << "3. Show Room Procces" << endl << "4. Exit" << endl;
	cin >> SelectProcces;

	switch (SelectProcces) {
	case 1:
		PatientProcces();
		break;
	case 2:
		Doctorprocces();
		break;
	case 3:
		RoomProcces();
		break;
	case 4:
		//system("cls");
		cout << "The System is Shutting Down." << endl;
		break;
	}
}

// -- - - - - Patient procces - - -  - //

void PatientProcces() {
	system("cls");
	int patpros;
	int PatientProccess;
	cout << "- - - Patient Procces - - -" << endl << "1. Add Patient " << endl << "2. Delete Patient " << endl << "3. List All Patient" << endl << "4. Show Patiant Disease " << endl << "5. Return the Previus Screen" << endl;
	cin >> PatientProccess;

	switch (PatientProccess)
	{
	case 1:
	{
		system("cls");
		
		cout << "- - - Add Patient - - -" << endl;
		AddPatient();
		cout << "Patient is added..." << endl << " - - - - - -" << endl;

		cout << " \nReturn the Patient Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> patpros;
		
		if (patpros == 1) {
			PatientProcces();
		}
		else {
			WelcomeScreen();
		}

		break;
	}
	case 2:
	{
		
		int i = 0;
		for (auto x : patientList) {
			cout << "*********" << ++i << " ********" << endl;		 
			x.printPatientInf();
		

		}

		int SelectPatientID;
		cout << "Enter Patient Number " << endl;
		cin >> SelectPatientID;
		if (patientList.size() == 0 || SelectPatientID > patientList.size()) {
			cout << "The doctor with the number you entered could not be found... !!!" << endl;
		}
		else{
		patientList.erase(patientList.begin() + SelectPatientID - 1);
		cout << " " << SelectPatientID << " is deleted." << endl;
		}

			

		cout << " \nReturn the Patient Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> patpros;

		if (patpros == 1) {
			PatientProcces();
		}
		else {
			WelcomeScreen();
		}


		break;
	}
	case 3:
		
		cout << "- - - Patient List - - -" << endl;
		for (auto x : patientList)
		{
			x.printPatientInf();
		}

		cout << " \nReturn the Patient Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> patpros;
		
		if (patpros == 1) {
			PatientProcces();
		}
		else {
			WelcomeScreen();
		}

		break;
	case 4:
		
		for (auto x : patientList) {
			x.showPatientDisease();
		}

		cout << " \nReturn the Patient Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> patpros;
		
		if (patpros == 1) {
			PatientProcces();
		}
		else {
			WelcomeScreen();
		}

		break;
	case 5:
		
		WelcomeScreen();

		break;
	}
}

// -- - - - - Doctor procces - - -  - //

void Doctorprocces() {
	system("cls");
	int docpros;
	int DoctorProcces;
	cout << "- - - Doctor Proces - - -" << endl << "1. Add New Doctor " << endl << "2. Delete Doctor " << endl << "3. List Doctor list "<< endl << "4. Show All Doctor Salary" << endl << "5. Return the Previus Screen" << endl;
	cin >> DoctorProcces;

	switch (DoctorProcces)
	{
	case 1:
	{
		system("cls");
		cout << "- - - Add Doctor - - -" << endl;
		AddDoctor();
		cout << "- - - Doctor is Added...  - - -" << endl;
		
		cout << " \nReturn the Doctor Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> docpros;
		if (docpros == 1) {
			Doctorprocces();
		}
		else {
			WelcomeScreen();
		}
		

		break;
	}
	case 2:{
		
		int i = 0;

		for (auto x: DoctorList){
			cout << "*** Doctor Number : " << i++ << " ***" << endl;
			x.printDoctorInf();
		
		}

		int SelectDoctorId;
		cout << "Enter Doctor Number " << endl;
		cin >> SelectDoctorId;

		
			if (DoctorList.size() == 0 || SelectDoctorId > DoctorList.size()){
			cout << "The doctor with the number you entered could not be found... !!!" << endl;
			}
			else {
				DoctorList.erase(DoctorList.begin() + SelectDoctorId-1);
				cout << " " << SelectDoctorId << " is deleted." << endl;
			}

		cout << " \nReturn the Doctor Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> docpros;
		if (docpros == 1) {
			Doctorprocces();
		}
		else {
			WelcomeScreen();
		}

		break;
	}
	case 3:

		cout << "- - - Doctor List - - -" << endl;
		for (auto x : DoctorList)
		{
			x.printDoctorInf();
			
		}

		cout << " \nReturn the Doctor Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> docpros;
		
		if (docpros == 1) {
			Doctorprocces();
		}
		else {
			WelcomeScreen();
		}

		break;
	case 4:
		for (auto x : DoctorList)
		{
			x.ShowDoctorSalary();
		}

		cout << " \nReturn the Doctor Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> docpros;
	
		if (docpros == 1) {
			Doctorprocces();
		}
		else {
			WelcomeScreen();
		}
		break;
	case 5:

		WelcomeScreen();

		break;
	}
}

// -- - - - - Room procces - - -  - //

void RoomProcces() {
	system("cls");

	int selectRoomProcces;
	cout << "- - - Room Prooces - - -" << endl << "1. Room Doctor List " << endl << "2. Room Patient list " << endl << "3. Room All Number List" << endl << "4. Return the Previus Screen" << endl;
	cin >> selectRoomProcces;

	switch (selectRoomProcces)
	{
	case 1:
		int roomPros;
		cout << "- - - Doctor Room List - - -" << endl;
		for (auto x : DoctorList)
		{
			x.PrintDoctorRoom();
		}
		
		cout << " \nReturn the Room Procces Press ( 1 ) "<< endl <<  "Return the Main Screen Press Any Key " << endl;
		cin >> roomPros;
		
		if (roomPros == 1) {
			RoomProcces();
		}
		else {
			WelcomeScreen();
		}
		

		break;
	case 2:
		int roomPros1;
		cout << "- - - Patient Room List - - -" << endl;

		for (auto x : patientList)
		{
			x.PrintPatientRoom();
		}
		
		cout << " \nReturn the Room Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> roomPros1;
		
		if (roomPros1 == 1) {
			RoomProcces();
		}
		else {
			WelcomeScreen();
		}

		break;
	case 3:
		for (auto x : DoctorList)
		{
			x.AllRoomNum();
		}
		cout << " \nReturn the Room Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> roomPros1;

		if (roomPros1 == 1) {
			RoomProcces();
		}
		else {
			WelcomeScreen();
		}

		break;
	case 4:
		WelcomeScreen();
		break;
	}
}