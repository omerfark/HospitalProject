#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RoomClass {
public:
	int RoomNumberDoctor[4] = {};
	int RoomNumberPatient[4] = {};

	RoomClass(int RoomNumberDoctor[4], int RoomNumberPatient[4]);
	void ShowRoomNum();
};

void RoomClass::ShowRoomNum() {
	cout << "Doctor Room Number  : " << RoomNumberDoctor << endl;
	cout << "Patient Room Number  : " << RoomNumberPatient  << endl;
}


//class DoctorClass {
//public:
//	//string DoctorName;
//	int DoctorId;
//	int DoctorSalary;
//	int DoctorRoom; //Array olmalý
//	DoctorClass( int DoctorId, int DoctorSalary, int DoctorRoom);
//
//	void ShowDoctorInf();
//	void ShowDoctorlýst();
//	void AddNewDoctor();
//	void DeleteDoctor();
// };
//
//vector<reference_wrapper<DoctorClass>> DoctorList;
//
//DoctorClass::DoctorClass( int DoctorId, int DoctorSalary, int DoctorRoom) {
//	this->DoctorId = DoctorId;
//	this->DoctorRoom = DoctorRoom;
//	this->DoctorSalary = DoctorSalary;
//	DoctorList.push_back(*this);
//}

//class NurseClass {
//public: 
//	string NurseName;
//	int NurseId;
//	int NurseSalary;
//	int NurseRoom; //Array olmalý
//
//	void ShowNurseInf();
//	void ShowNurselýst();
//	void AddNewNurse();
//	void DeleteNurse();
//};
//
//class PatientClass {
//	string PatientName;
//	int PatientId;
//	int PatientAge;
//	int PatientRoom; //Array olmalý
//
//	void ShowPatientInf();
//	void ShowPatientlýst();
//	void AddNewPatient();
//	void DeletePatient();
//};
