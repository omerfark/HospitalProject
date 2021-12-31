#include <string>
#include <iostream>
#include <vector>

using namespace std;

void WelcomeScreen_forAdmin();
void Adminmanagement_panel();
void WelcomeScreen_forpatient();
void welcomescreen_General();

void PatientProcces_forPatient();
void PatientProcces_forAdmin();
void AddPatient();
void printPatientInf();
void showPatientDisease();
void PrintPatientRoom();
void showpatientGender();
void patientRoomController();
void patientIdController(int x);
void showpatientprecedence();

void Doctorprocces();
void AddDoctor();
void printDoctorInf();
void PrintDoctorRoom();
void ShowDoctorGender();
void ShowDoctorSalary();
void doctorgendercontroller();
void doctorRoomController();
void DoctorIdController(int x);

void Nurseprocces();
void AddNurse();
void printNurseInf();
void PrintNurserRoom();
void ShowNurseSalary();
void ShowNurseGender();
void NurseGenderController();
void NurseRoomController();
void NurseIdController(int x);

void RoomProcces();

//32

//------------------Patient Class---------------//

class PatientClass {
public:
	string Pname;
	int Page;
	int Pid;
	string PDisease;
	int PRoomnum;
	char PGender;
	int Pprecedence;

	PatientClass(string Pname, int Page, int Pid, string PDisease, int PRoomnum, char PGender, int Pprecedence);


	void printPatientInf() {
		cout << "- - - - - - - - - - - " << endl;
		cout << "Patient Name: " << Pname << endl;
		cout << "Patient Age: " << Page << endl;
		cout << "Patient Id: " << Pid << endl;
		cout << "Patient Disease: " << PDisease << endl;
		cout << "Patient Room Number:  " << PRoomnum << endl;
		if (PGender == 'M') {
			cout << "Doctor Gender: Male " << endl;
		}
		else {
			cout << "Doctor Gender: Female " << endl;
		}
		
		if (Pprecedence == 1) {
			cout << "Patient Precedence : " << "[1 - Green]" << endl;
		}
		else if (Pprecedence == 2) {
			cout << "Patient Precedence : " << "[2 - Yellow]" << endl;
		}
		else if (Pprecedence == 3) {
			cout << "Patient Precedence : " << "[3 - Red]" << endl;
		}
		else {
			cout << "Invalid Precedence !!! " << endl;
		}	   
		cout << "- - - - - - - - - - - " << endl;
	}

	void PrintPatientRoom() {
		cout << "Patient Name : " << Pname;
		cout << " -- Patient Room Number is : " << PRoomnum << endl;
	}

	void showPatientDisease() {
		cout << "Patient Name:  " << Pname << " - Patieent Disease: " << PDisease << endl;
	}
	void showpatientGender() {
		if (PGender == 'M') {
			cout << "Patient " << Pname << " gender is Male " << endl;
		}
		else {

			cout << "Patient " << Pname << " gender is Female" << endl;
		}
	}

	void showpatientprecedence(){
		if (Pprecedence == 1) {
			cout << "Patient "<< Pname <<  " - Precedence : [1 - Green] " << endl;
		}
		else if (Pprecedence == 2) {
			cout << "Patient " << Pname << " - Precedence : [2 - Yellow] " << endl;
		}
		else if (Pprecedence == 3) {
			cout << "Patient " << Pname << " - Precedence : [3 - Red] " << endl;
		}
		else {
			cout << "Invalid Precedence !!! " << endl;
		}
	}
};

vector<PatientClass> patientList;


PatientClass::PatientClass(string Pname, int Page, int Pid, string PDisease, int PRoomnum, char PGender , int Pprecedence) {
	this->Pname = Pname;
	this->Page = Page;
	this->Pid = Pid;
	this->PDisease = PDisease;
	this->PRoomnum = PRoomnum;
	this->PGender = PGender;
	this->Pprecedence = Pprecedence;
	patientList.push_back(*this);
}

// - - - - - - Add Patient - - - - - - //

void AddPatient() {

	string Name;
	int Age;
	int Id;
	string Disease;
	int roomnum;
	char Gender;
	int precedence;

	cout << "Name: ";
	cin >> Name;
	cout << "Age:  ";
	cin >> Age;
	cout << endl << "For Doctor [ 1 0 _ _ ]" << endl;
	cout << "For Nurse [ 2 0 _ _ ]" << endl;
	cout << "For Patient [ 3 0 _ _ ]" << endl;
	cout << endl << "Id: ";
	cin >> Id;
	cout << "Disease: ";
	cin >> Disease;
	cout << "Room number: ";
	cin >> roomnum;
	cout << "Gender (Male[M] - Female[F]): ";
	cin >> Gender;
	cout << "Precedence " << endl << "[1 - Green]" << endl << "[2 - Yellow]" << endl << "[3 - Red]" << endl;
	cin >> precedence;
	PatientClass newPatient2(Name, Age, Id, Disease, roomnum, Gender, precedence);

	patientIdController(Id);

	patientRoomController();
}

// - - - - - -  - - - - Patient Id contoller  - - - - -//

void patientIdController(int x)
{
	if (x >= 1000)
		patientIdController(x / 1000);

	int digit = x % 100;

	//cout << digit << " - ";

	while (digit < 4) {

		if (digit == 3) {
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			cout << "Patient Id is valid. " << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			PatientProcces_forAdmin();
			break;
		}
		else if (digit == 2) {
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			cout << "This Id is Nurse ID. Please re-entered patient Id: " << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			patientList.erase(patientList.end() - 1);
			AddPatient();
			break;
		}
		else if (digit == 1) {
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			cout << "This Id is Doctor ID. Please re-entered patient Id:" << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			patientList.erase(patientList.end() - 1);
			AddPatient();
			break;
		}
		else {
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			cout << "The id number you entered does not valid !!!" << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			patientList.erase(patientList.end() - 1);
			break;
		}

	}
}

// - - - - - - Patient room Controller - - - - - - //

void patientRoomController() {
	int room1 = 0, room2 = 0, room3 = 0, room4 = 0, room5 = 0, room6 = 0;
	for (auto x : patientList) {
		if (x.PRoomnum == 1) {
			room1++;
		}
		else if (x.PRoomnum == 2) {
			room2++;
		}
		else if (x.PRoomnum == 3) {
			room3++;
		}
		else if (x.PRoomnum == 4) {
			room4++;
		}
		else if (x.PRoomnum == 5) {
			room5++;
		}
		else if (x.PRoomnum == 6) {
			room6++;
		}
	}

	if (room1 > 1) {
		cout << "- - - - - - - - - - - - " << endl;
		cout << "Room is not empty !!!" << endl;
		cout << "Please try another rooms number." << endl;
		cout << "- - - - - - - - - - - - " << endl;
		patientList.erase(patientList.end() - 1);
		AddPatient();
	}
	else if (room2 > 1) {
		cout << "- - - - - - - - - - - - " << endl;
		cout << "Room is not empty !!!" << endl;
		cout << "Please try another rooms number." << endl;
		cout << "- - - - - - - - - - - - " << endl;
		patientList.erase(patientList.end() - 1);
		AddPatient();
	}
	else if (room3 > 1) {
		cout << "- - - - - - - - - - - - " << endl;
		cout << "Room is not empty !!!" << endl;
		cout << "Please try another rooms number." << endl;
		cout << "- - - - - - - - - - - - " << endl;
		patientList.erase(patientList.end() - 1);
		AddPatient();
	}
	else if (room4 > 1) {
		cout << "- - - - - - - - - - - - " << endl;
		cout << "Room is not empty !!!" << endl;
		cout << "Please try another rooms number." << endl;
		cout << "- - - - - - - - - - - - " << endl;
		patientList.erase(patientList.end() - 1);
		AddPatient();
	}
	else if (room5 > 1) {
		cout << "- - - - - - - - - - - - " << endl;
		cout << "Room is not empty !!!" << endl;
		cout << "Please try another rooms number." << endl;
		cout << "- - - - - - - - - - - - " << endl;
		patientList.erase(patientList.end() - 1);
		AddPatient();
	}
	else if (room6 > 1) {
		cout << "- - - - - - - - - - - - " << endl;
		cout << "Room is not empty !!!" << endl;
		cout << "Please try another rooms number." << endl;
		cout << "- - - - - - - - - - - - " << endl;
		patientList.erase(patientList.end() - 1);
		AddPatient();

	}
	else {
		PatientProcces_forAdmin();
	}



}

//------------------Doctor Class---------------//

class DoctorClass {
public:
	string DName;
	int DAge;
	int DId;
	double DSalary;
	int  DRoomnum;
	char DGender;

	DoctorClass(string DName, int DAge, int DId, double DSalary, int DRoomnum, char Dgender);


	void printDoctorInf() {
		cout << "- - - - - - - - - - - " << endl;
		cout << "Doctor Name: " << DName << endl;
		cout << "Doctor Age: " << DAge << endl;
		cout << "Doctor Id: " << DId << endl;
		cout << "Doctor Salary: " << DSalary << endl;
		cout << " Doctor Room Number : " << DRoomnum << endl;
		if (DGender == 'M') {
			cout << "Doctor Gender: Male " << endl;
		}
		else {
			cout << "Doctor Gender: Female " << endl;
		}
		cout << "- - - - - - - - - - - " << endl;

	}

	void PrintDoctorRoom() {
		cout << "Doctor Name : " << DName;
		cout << " -- Doctor Room Number is : " << DRoomnum << endl;


	}

	void AllRoomNum() {
		cout << "Avaliable Room Number:   " << DRoomnum << endl;
	}

	void ShowDoctorSalary() {
		cout << "Doctor " << DName << " salary is " << DSalary << endl;
	}

	void ShowDoctorGender() {
		if (DGender == 'M') {
			cout << "Doctor " << DName << " gender is Male " << endl;
		}
		else {

			cout << "Doctor " << DName << " gender is Female" << endl;
		}

	}
};

vector<DoctorClass> DoctorList;

DoctorClass::DoctorClass(string DName, int DAge, int DId, double DSalary, int DRoomnum, char DGender) {
	this->DName = DName;
	this->DAge = DAge;
	this->DId = DId;
	this->DSalary = DSalary;
	this->DRoomnum = DRoomnum;
	this->DGender = DGender;
	DoctorList.push_back(*this);

}

// - - - - - - Add Doctor - - - - - - //

void AddDoctor() {

	string DocName;
	int DocAge;
	int DocId;
	double DocSalary;
	int Docroomnum;
	char DocGender;

	cout << "Name: ";
	cin >> DocName;
	cout << "Age:  ";
	cin >> DocAge;
	cout << endl << "For Doctor [ 1 0 _ _ ]" << endl;
	cout << "For Nurse [ 2 0 _ _ ]" << endl;
	cout << "For Patient [ 3 0 _ _ ]" << endl;
	cout << endl << "Id: ";
	cin >> DocId;
	cout << "Salary: ";
	cin >> DocSalary;
	cout << "Room number: ";
	cin >> Docroomnum;
	cout << "Gender (Male[M] - Female[F]): ";
	cin >> DocGender;


	// - - - - - Age of doctor cotroller - - - - // 
	if (DocAge < 24) {
		cout << "Doctor age is not enough !!!" << endl;
		cout << "Please re-enter the information " << endl;
		AddDoctor();
	}
	else {
		DoctorClass newDoctor(DocName, DocAge, DocId, DocSalary, Docroomnum, DocGender);
	}

	DoctorIdController(DocId);

	doctorgendercontroller();

}

//- - - - - - -  Doctor Id controller - - - - //

void DoctorIdController(int x) {
	if (x >= 1000)
		DoctorIdController(x / 1000);

	int digit = x % 100;

	while (digit < 4) {

		if (digit == 3) {
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			cout << "This Id is Patient ID. Please re-entered patient Id: " << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			DoctorList.erase(DoctorList.end() - 1);
			AddDoctor();
			break;
		}
		else if (digit == 2) {
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			cout << "This Id is Nurse ID. Please re-entered patient Id: " << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			DoctorList.erase(DoctorList.end() - 1);
			AddDoctor();
			break;
		}
		else if (digit == 1) {
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			cout << "Doctor Id is valid. " << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			Doctorprocces();
			break;
		}
		else {
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			cout << "The id number you entered does not valid !!!" << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			DoctorList.erase(DoctorList.end() - 1);
			break;
		}

	}
}

// - - - - - - Doctor Room Controller  - - - - - //

void doctorRoomController() {
	int room1 = 0;
	int room2 = 0;
	int room3 = 0;
	for (auto x : DoctorList) {
		if (x.DRoomnum == 1 || x.DRoomnum == 2) {
			room1++;
		}
		else if (x.DRoomnum == 3 || x.DRoomnum == 4) {
			room2++;
		}
		else if (x.DRoomnum == 5 || x.DRoomnum == 6) {
			room3++;
		}
	}

	room1--;
	room2--;
	room3--;

	if (room1 >= 2) {
		cout << "- - - - - - - - - - - - " << endl;
		cout << "Rooms are already full." << endl;
		cout << "- - - - - - - - - - - - " << endl;
		DoctorList.erase(DoctorList.end() - 1);  //Eðer odalar doluysa kod bu koþulu saðlayarak son girilen bilgileri siler.
		AddDoctor();
	}
	else if (room2 >= 2) {
		cout << "- - - - - - - - - - - - " << endl;
		cout << "Rooms are already full." << endl;
		cout << "- - - - - - - - - - - - " << endl;
		DoctorList.erase(DoctorList.end() - 1); //Eðer odalar doluysa kod bu koþulu saðlayarak son girilen bilgileri siler.
		AddDoctor();
	}
	else if (room2 >= 2) {
		cout << "- - - - - - - - - - - - " << endl;
		cout << "Rooms are already full." << endl;
		cout << "- - - - - - - - - - - - " << endl;
		DoctorList.erase(DoctorList.end() - 1); //Eðer odalar doluysa kod bu koþulu saðlayarak son girilen bilgileri siler.
		AddDoctor();
	}
	else {
		Doctorprocces();
	}
}

// - - - - - Gender of doctor control - - - - //

void doctorgendercontroller() {
	int male = 0;
	int female = 0;
	for (auto x : DoctorList) {
		if (x.DGender == 'M') {
			male++;
		}
		else {
			female++;
		}
	}
	female--;
	male--;

	if (male >= 2) {
		cout << "Male doctor quota has been reached." << endl;
		DoctorList.erase(DoctorList.end() - 1);  //Eklenen doktorun cinsiyetini kabul etmediði için son girilen bilgileri siliyor.
		Doctorprocces();
	}
	else if (female >= 2) {
		cout << "Female doctor quota has been reached." << endl;
		DoctorList.erase(DoctorList.end() - 1);   //Eklenen doktorun cinsiyetini kabul etmediði için son girilen bilgileri siliyor.
		Doctorprocces();
	}
	else {
		Doctorprocces();
	}


}

// ----------------Nurse Class---------------//

class NurseClass {
public:
	string NName;
	int NAge;
	int NId;
	int NSalary;
	int NRoomnum;
	char NGender;

	NurseClass(string NName, int NAge, int NId, int NSlaray, int NRoomnum, char NGender);

	void printNurseInf() {
		cout << "- - - - - - - - - - - " << endl;
		cout << "Nurse Name: " << NName << endl;
		cout << "Nurse Age: " << NAge << endl;
		cout << "Nurse Id: " << NId << endl;
		cout << "Nurse Salary: " << NSalary << endl;
		cout << "Nurse Room Number:  " << NRoomnum << endl;
		cout << "Nurse Gender: " << NGender << endl;
		if (NGender == 'M') {
			cout << "Nurse Gender: Male " << endl;
		}
		else {
			cout << "Nurse Gender: Female " << endl;
		}
		cout << "- - - - - - - - - - - " << endl;
	}

	void PrintNurserRoom() {
		cout << "Nurse Name : " << NName;
		cout << " -- Nurse Room Number is : " << NRoomnum << endl;
	}

	void AllRoomNum() {
		cout << "Avaliable Room Number:   " << NRoomnum << endl;
	}

	void ShowNurseSalary() {
		cout << "Nurse " << NName << " salary is " << NSalary << endl;
	}

	void ShowNurseGender() {
		if (NGender == 'M') {
			cout << "Nurse " << NName << " gender is Male " << endl;
		}
		else {

			cout << "Nurse " << NName << " gender is Female" << endl;
		}
	}

};

vector<NurseClass> NurseList;

NurseClass::NurseClass(string NName, int NAge, int NId, int NSalary, int NRoomnum, char NGender) {
	this->NName = NName;
	this->NAge = NAge;
	this->NId = NId;
	this->NSalary = NSalary;
	this->NRoomnum = NRoomnum;
	this->NGender = NGender;
	NurseList.push_back(*this);
}

// - - - - - - Add Nurse - - - - - - //

void AddNurse() {
	string NurName;
	int NurAge;
	int NurId;
	int NurSalary;
	int Nurroomnum;
	char NurGender;

	cout << "Name: ";
	cin >> NurName;
	cout << "Age:  ";
	cin >> NurAge;
	cout << endl << "For Doctor [ 1 0 _ _ ]" << endl;
	cout << "For Nurse [ 2 0 _ _ ]" << endl;
	cout << "For Patient [ 3 0 _ _ ]" << endl;
	cout << endl << "Id: ";
	cin >> NurId;
	cout << "Salary: ";
	cin >> NurSalary;
	cout << "Room number: ";
	cin >> Nurroomnum;
	cout << "Gender (Male[M] - Female[F]): ";
	cin >> NurGender;

	// - - - - - Age of Nurse cotroller - - - - // 
	if (NurAge < 18) {
		cout << "Nurse age is not enough !!!" << endl;
		cout << "Please re-enter the information " << endl;
		AddDoctor();
	}
	else {
		NurseClass newNurse(NurName, NurAge, NurId, NurSalary, Nurroomnum, NurGender);
	}
	NurseIdController(NurId);
	NurseRoomController();
	NurseGenderController();

}

void NurseIdController(int x) {
	if (x >= 1000)
		NurseIdController(x / 1000);

	int digit = x % 100;

	while (digit < 4) {

		if (digit == 3) {
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			cout << "This Id is Patient ID. Please re-entered patient Id: " << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			NurseList.erase(NurseList.end() - 1);
			AddNurse();
			break;
		}
		else if (digit == 2) {
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			cout << "Nurse Id is valid.  " << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			Nurseprocces();
			break;
		}
		else if (digit == 1) {
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			cout << "This Id is Doctor ID. Please re-entered patient Id:" << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			NurseList.erase(NurseList.end() - 1);
			AddNurse();
			break;
		}
		else {
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			cout << "The id number you entered does not valid !!!" << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			NurseList.erase(NurseList.end() - 1);
			break;
		}

	}
}

// - - - - - - Nurse Room Controller - - - - //

void NurseRoomController() {
	int room1 = 0, room2 = 0, room3 = 0, room4 = 0, room5 = 0, room6 = 0;
	for (auto x : NurseList) {
		if (x.NRoomnum == 1) {
			room1++;
		}
		else if (x.NRoomnum == 2) {
			room2++;
		}
		else if (x.NRoomnum == 3) {
			room3++;
		}
		else if (x.NRoomnum == 4) {
			room4++;
		}
		else if (x.NRoomnum == 5) {
			room5++;
		}
		else if (x.NRoomnum == 6) {
			room6++;
		}
	}

	if (room1 > 1) {
		cout << "- - - - - - - - - - - - " << endl;
		cout << "Room is not empty !!!" << endl;
		cout << "Please try another rooms number." << endl;
		cout << "- - - - - - - - - - - - " << endl;
		NurseList.erase(NurseList.end() - 1);
		AddNurse();
	}
	else if (room2 > 1) {
		cout << "- - - - - - - - - - - - " << endl;
		cout << "Room is not empty !!!" << endl;
		cout << "Please try another rooms number." << endl;
		cout << "- - - - - - - - - - - - " << endl;
		NurseList.erase(NurseList.end() - 1);
		AddNurse();
	}
	else if (room3 > 1) {
		cout << "- - - - - - - - - - - - " << endl;
		cout << "Room is not empty !!!" << endl;
		cout << "Please try another rooms number." << endl;
		cout << "- - - - - - - - - - - - " << endl;
		NurseList.erase(NurseList.end() - 1);
		AddNurse();
	}
	else if (room4 > 1) {
		cout << "- - - - - - - - - - - - " << endl;
		cout << "Room is not empty !!!" << endl;
		cout << "Please try another rooms number." << endl;
		cout << "- - - - - - - - - - - - " << endl;
		NurseList.erase(NurseList.end() - 1);
		AddNurse();
	}
	else if (room5 > 1) {
		cout << "- - - - - - - - - - - - " << endl;
		cout << "Room is not empty !!!" << endl;
		cout << "Please try another rooms number." << endl;
		cout << "- - - - - - - - - - - - " << endl;
		NurseList.erase(NurseList.end() - 1);
		AddNurse();
	}
	else if (room6 > 1) {
		cout << "- - - - - - - - - - - - " << endl;
		cout << "Room is not empty !!!" << endl;
		cout << "Please try another rooms number." << endl;
		cout << "- - - - - - - - - - - - " << endl;
		NurseList.erase(NurseList.end() - 1);
		AddNurse();

	}
	else {
		Nurseprocces();
	}

}

// - - - - - Gender of Nurse control - - - - //

void NurseGenderController() {
	int male = 0;
	int female = 0;
	for (auto x : NurseList) {
		if (x.NGender == 'M') {
			male++;
		}
		else {
			female++;
		}
	}
	female--;
	male--;

	if (male >= 4) {
		cout << "Male nurse quota has been reached." << endl;
		NurseList.erase(NurseList.end() - 1);  //Eklenen Hemþirenin cinsiyetini kabul etmediði için son girilen bilgileri siliyor.
		Nurseprocces();
	}
	else if (female >= 4) {
		cout << "Female nurse quota has been reached." << endl;
		NurseList.erase(NurseList.end() - 1);   //Eklenen Hemþirenin cinsiyetini kabul etmediði için son girilen bilgileri siliyor.
		Doctorprocces();
	}
	else {
		Nurseprocces();
	}
}

int main() {

	DoctorClass doctor1("Ferhat", 29, 1020, 20500, 1, 'M');
	DoctorClass doctor2("Ayse", 32, 1021, 25500, 1, 'F');

	NurseClass nurse1("Emir", 26, 2020, 12000, 1, 'M');
	NurseClass nurse2("Nur", 20, 2021, 10000, 2, 'F');

	PatientClass patient1("ahmet", 45, 3020, "Heart", 1, 'M',2);
	PatientClass patient2("omer", 54, 3021, "respiratory", 2, 'F',1);

	welcomescreen_General();

	return 0;
}

// - - - - - - Welcome screen General - - - - - -// 

void welcomescreen_General() {
	int procces1;
	cout << "    - - - - - - - - - - - - - - - - - -   " << endl;
	cout << "	Welcome the Hospital Sistem	" << endl;
	cout << endl << " SELECT: " << endl << "1. Admin login System " << endl << "2. Patient Record system" << endl;
	cin >> procces1;
	switch (procces1)
	{
	case 1:
		Adminmanagement_panel();
		break;
	case 2:
		WelcomeScreen_forpatient();
		break;
	default:
		cout << " - - - - - - - - - - - - - - - " << endl;
		cout << "Please entered valid number." << endl;
		cout << " - - - - - - - - - - - - - - - " << endl;
		welcomescreen_General();
		break;
	}
}


// - - -  - - - - - - Welcome Screen for patient - - - - - -//

void WelcomeScreen_forpatient() {
	system("cls");
	int Selectedproc;
	cout << "SELECT: " << endl << "1. Show Patient Procces " << endl << "2. Show Patient Room Procces" << endl << "3. Exit" << endl;
	cin >> Selectedproc;
	switch (Selectedproc)
	{
	case 1:
		PatientProcces_forPatient();
		break;
	case 2:
		system("cls");
		int roomPros1;
		cout << "- - - Patient Room List - - -" << endl;

		for (auto x : patientList)
		{
			x.PrintPatientRoom();
		}

		cout << " \nReturn the Patient Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> roomPros1;

		if (roomPros1 == 1) {
			WelcomeScreen_forpatient();
		}
		else {
			welcomescreen_General();
		}
		break;
	case 3:
		system("cls");
		cout << "The System is Shutting Down." << endl;
		break;
	default:
		cout << " - - - - - - - - - - - - - - - " << endl;
		cout << "Please entered valid number." << endl;
		cout << " - - - - - - - - - - - - - - - " << endl;
		WelcomeScreen_forpatient();
		break;
	}
}

// - - -  - - - - - - Admin password control panel - - - - - -//

void Adminmanagement_panel() {
	int adminpassword = 12345;
	int enterpassword;

	cout << "Please admin password: ";
	cin >> enterpassword;

	if (adminpassword == enterpassword) {
		cout << "    - - - - - - - - - - - - - - - - - -   " << endl;
		cout << "    Welcome the Hospital Manager Sistem    " << endl;
		WelcomeScreen_forAdmin();
	}
	else {

		cout << "Password is FALSE !!!" << endl;
		cout << "Exiting the system." << endl;
		cout << "    - - - - - - - - - - - - - - - - - -   " << endl;
		int screenpros = 0;
		cout << "Press 1 to try again. " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> screenpros;
		cout << "    - - - - - - - - - - - - - - - - - -   " << endl;

		if (screenpros == 1) {
			Adminmanagement_panel();
		}
		else {
			welcomescreen_General();
		}
	}


}

//-------Welcome Screen for Admin---------//

void WelcomeScreen_forAdmin() {
	int SelectProcces;
	cout << "SELECT: " << endl << "1. Show Patient Procces " << endl << "2. Show Doctor Procces" << endl << "3. Show Nurse Procces" << endl << "4. Show Room Procces" << endl << "5. Exit" << endl;
	cin >> SelectProcces;

	switch (SelectProcces) {
	case 1:
		PatientProcces_forAdmin();
		break;
	case 2:
		Doctorprocces();
		break;
	case 3:
		Nurseprocces();
		break;
	case 4:
		RoomProcces();

		break;
	case 5:
		system("cls");
		cout << "The System is Shutting Down." << endl;
		break;
	default:
		cout << " - - - - - - - - - - - - - - - " << endl;
		cout << "Please entered valid number." << endl;
		cout << " - - - - - - - - - - - - - - - " << endl;
		WelcomeScreen_forAdmin();
	}
}

// -- - - - -[ ADMÝN ] Patient procces - - -  - //

void PatientProcces_forAdmin() {
	//system("cls");
	int patpros;
	int PatientProccess;
	cout << "- - - Patient Procces - - -" << endl << "1. Add Patient " << endl << "2. Delete Patient " << endl << "3. List All Patient" << endl << "4. Show Patiant Disease " << endl <<  "5. Show Patient Gender "  << endl <<"6. Show Patient Precedence"  << endl << "7. Return the Previus Screen" << endl;
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
			PatientProcces_forAdmin();
		}
		else {
			WelcomeScreen_forAdmin();
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
		else {
			patientList.erase(patientList.begin() + SelectPatientID - 1);
			cout << " " << SelectPatientID << " is deleted." << endl;
		}

		cout << " \nReturn the Patient Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> patpros;

		if (patpros == 1) {
			PatientProcces_forAdmin();
		}
		else {
			WelcomeScreen_forAdmin();
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
			PatientProcces_forAdmin();
		}
		else {
			WelcomeScreen_forAdmin();
		}

		break;
	case 4:

		for (auto x : patientList) {
			x.showPatientDisease();
		}

		cout << " \nReturn the Patient Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> patpros;

		if (patpros == 1) {
			PatientProcces_forAdmin();
		}
		else {
			WelcomeScreen_forAdmin();
		}

		break;
	case 5:

		for (auto x : patientList) {
			x.showpatientGender();
		}

		cout << " \nReturn the Patient Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> patpros;

		if (patpros == 1) {
			PatientProcces_forAdmin();
		}
		else {
			WelcomeScreen_forAdmin();
		}
		break;
	case 6:
		for (auto x : patientList) {
			x.showpatientprecedence();
		}
		cout << " \nReturn the Patient Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> patpros;

		if (patpros == 1) {
			PatientProcces_forAdmin();
		}
		else {
			WelcomeScreen_forAdmin();
		}
		break;
	case 7:

		WelcomeScreen_forAdmin();

		break;
	default:
		cout << " - - - - - - - - - - - - - - - " << endl;
		cout << "Please entered valid number." << endl;
		cout << " - - - - - - - - - - - - - - - " << endl;
		WelcomeScreen_forAdmin();
	}
}

// -- - - - -jUST Patient procces - - -  - //

void PatientProcces_forPatient() {
	int patientproc;
	int PatientProccess;
	cout << "- - - Patient Procces - - -" << endl << "1. List All Patient" << endl << "2. Show Patiant Disease " << endl << "3. Show Patient Gender "<< endl << "4. Show Patient Precedence" << endl << "5. Return the Previus Screen" << endl;
	cin >> PatientProccess;

	switch (PatientProccess)
	{

	case 1:
		system("cls");
		cout << "- - - Patient List - - -" << endl;
		for (auto x : patientList)
		{
			x.printPatientInf();
		}

		cout << " \nReturn the Patient Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> patientproc;

		if (patientproc == 1) {
			PatientProcces_forPatient();
		}
		else {
			WelcomeScreen_forpatient();
		}

		break;
	case 2:
		system("cls");
		for (auto x : patientList) {
			x.showPatientDisease();
		}

		cout << " \nReturn the Patient Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> patientproc;

		if (patientproc == 1) {
			PatientProcces_forPatient();
		}
		else {
			WelcomeScreen_forpatient();
		}

		break;
	case 3:
		system("cls");
		for (auto x : patientList) {
			x.showpatientGender();
		}

		cout << " \nReturn the Patient Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> patientproc;

		if (patientproc == 1) {
			PatientProcces_forPatient();
		}
		else {
			WelcomeScreen_forpatient();
		}
		break;

	case 4:
		for (auto x : patientList) {
			x.showpatientprecedence();
		}
		cout << " \nReturn the Patient Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> patientproc;

		if (patientproc == 1) {
			PatientProcces_forAdmin();
		}
		else {
			WelcomeScreen_forAdmin();
		}
		break;
	case 5:

		WelcomeScreen_forpatient();

		break;
	default:
		cout << " - - - - - - - - - - - - - - - " << endl;
		cout << "Please entered valid number." << endl;
		cout << " - - - - - - - - - - - - - - - " << endl;
		WelcomeScreen_forpatient();
	}
}

// -- - - - - Doctor procces - - -  - //

void Doctorprocces() {
	int docpros;
	int DoctorProcces;
	cout << "- - - Doctor Proces - - -" << endl << "1. Add New Doctor " << endl << "2. Delete Doctor " << endl << "3. List Doctor list " << endl << "4. Show All Doctor Salary" << endl << "5. Show Doctor Gender" << endl << "6. Return the Previus Screen" << endl;
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
			WelcomeScreen_forAdmin();
		}

		break;
	}
	case 2: {
		system("cls");
		int i = 0;

		for (auto x : DoctorList) {
			cout << "*** Doctor Number : " << ++i << " ***" << endl;
			x.printDoctorInf();

		}

		int SelectDoctorId;
		cout << "Enter Doctor Number " << endl;
		cin >> SelectDoctorId;

		if (DoctorList.size() == 0 || SelectDoctorId > DoctorList.size()) {
			cout << "The doctor with the number you entered could not be found... !!!" << endl;
		}
		else {
			DoctorList.erase(DoctorList.begin() + SelectDoctorId - 1);
			cout << " " << SelectDoctorId << " is deleted." << endl;
		}

		cout << " \nReturn the Doctor Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> docpros;
		if (docpros == 1) {
			Doctorprocces();
		}
		else {
			WelcomeScreen_forAdmin();
		}

		break;
	}
	case 3:
		system("cls");
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
			WelcomeScreen_forAdmin();
		}

		break;
	case 4:
		system("cls");
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
			WelcomeScreen_forAdmin();
		}
		break;
	case 5:
		for (auto x : DoctorList) {
			x.ShowDoctorGender();
		}
		cout << " \nReturn the Doctor Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> docpros;

		if (docpros == 1) {
			Doctorprocces();
		}
		else {
			WelcomeScreen_forAdmin();
		}
		break;
	case 6:
		WelcomeScreen_forAdmin();

		break;
	default:
		system("cls");
		cout << " - - - - - - - - - - - - - - - " << endl;
		cout << "Please entered valid number." << endl;
		cout << " - - - - - - - - - - - - - - - " << endl;
		WelcomeScreen_forAdmin();
	}
}

// - - - - - Nurse procces - - - - //

void Nurseprocces() {
	int Nurpros;
	int NurseProcces;
	cout << "- - - Nurse Proces - - -" << endl << "1. Add New Nurse " << endl << "2. Delete Nurse " << endl << "3. List Nurse list " << endl << "4. Show All Nurse Salary" << endl << "5. Show Nurse Gender " << endl << "6. Return the Previus Screen" << endl;
	cin >> NurseProcces;

	switch (NurseProcces)
	{
	case 1:
	{
		system("cls");
		cout << "- - - Add Nurse - - -" << endl;
		AddNurse();
		cout << "- - - Nurse is Added...  - - -" << endl;

		cout << " \nReturn the Nurse Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> Nurpros;
		if (Nurpros == 1) {
			Nurseprocces();
		}
		else {
			WelcomeScreen_forAdmin();
		}


		break;
	}
	case 2: {
		system("cls");
		int i = 0;

		for (auto x : NurseList) {
			cout << "*** Nurse Number : " << ++i << " ***" << endl;
			x.printNurseInf();

		}

		int SelectNurseId;
		cout << "Enter Nurse Number " << endl;
		cin >> SelectNurseId;


		if (NurseList.size() == 0 || SelectNurseId > NurseList.size()) {
			cout << "The Nurse with the number you entered could not be found... !!!" << endl;
		}
		else {
			NurseList.erase(NurseList.begin() + SelectNurseId - 1);
			cout << " " << SelectNurseId << " is deleted." << endl;
		}

		cout << " \nReturn the Nurse Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> Nurpros;
		if (Nurpros == 1) {
			Nurseprocces();
		}
		else {
			WelcomeScreen_forAdmin();
		}

		break;
	}
	case 3:
		system("cls");
		cout << "- - - Doctor List - - -" << endl;
		for (auto x : NurseList)
		{
			x.printNurseInf();

		}

		cout << " \nReturn the Nurse Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> Nurpros;

		if (Nurpros == 1) {
			Nurseprocces();
		}
		else {
			WelcomeScreen_forAdmin();
		}

		break;
	case 4:
		system("cls");
		for (auto x : NurseList)
		{
			x.ShowNurseSalary();
		}

		cout << " \nReturn the Nurse Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> Nurpros;

		if (Nurpros == 1) {
			Nurseprocces();
		}
		else {
			WelcomeScreen_forAdmin();
		}
		break;
	case 5:
		for (auto x : NurseList) {
			x.ShowNurseGender();
		}
		cout << " \nReturn the Nurse Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> Nurpros;

		if (Nurpros == 1) {
			Nurseprocces();
		}
		else {
			WelcomeScreen_forAdmin();
		}
		break;
	case 6:

		WelcomeScreen_forAdmin();

		break;
	default:
		system("cls");
		cout << " - - - - - - - - - - - - - - - " << endl;
		cout << "Please entered valid number." << endl;
		cout << " - - - - - - - - - - - - - - - " << endl;
		WelcomeScreen_forAdmin();
	}
}

// -- - - - - Room procces - - -  - //

void RoomProcces() {
	int roomPros;
	int selectRoomProcces;
	cout << "- - - Room Prooces - - -" << endl << "1. Room Doctor List " << endl << "2. Room Patient list " << endl << "3. Room Nurse List" << endl << "4. Room All Number List" << endl << "5. Return the Previus Screen" << endl;
	cin >> selectRoomProcces;

	switch (selectRoomProcces)
	{
	case 1:
		system("cls");
		cout << "- - - Doctor Room List - - -" << endl;
		for (auto x : DoctorList)
		{
			x.PrintDoctorRoom();
		}

		cout << " \nReturn the Room Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> roomPros;

		if (roomPros == 1) {
			RoomProcces();
		}
		else {
			WelcomeScreen_forAdmin();
		}

		break;
	case 2:
		system("cls");
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
			WelcomeScreen_forAdmin();
		}

		break;
	case 3:
		system("cls");
		for (auto x : NurseList) {
			x.PrintNurserRoom();
		}

		cout << " \nReturn the Room Procces Press ( 1 ) " << endl << "Return the Main Screen Press Any Key " << endl;
		cin >> roomPros1;

		if (roomPros1 == 1) {
			RoomProcces();
		}
		else {
			WelcomeScreen_forAdmin();
		}

		break;

	case 4:
		system("cls");
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
			WelcomeScreen_forAdmin();
		}

		break;
	case 5:
		WelcomeScreen_forAdmin();
		break;
	default:
		system("cls");
		cout << " - - - - - - - - - - - - - - - " << endl;
		cout << "Please entered valid number." << endl;
		cout << " - - - - - - - - - - - - - - - " << endl;
		WelcomeScreen_forAdmin();
	}
}
