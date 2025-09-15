#include<iostream>
#include<string>
using namespace std;
//Function Declarations
void registerPatient(string &name, int &age, string &disease);
void assignDoctor(string &disease, string &doctor);
void assignRoom(string &disease, string &roomType, int &nursesRequired);
void selectTests(string &tests, float &testcharges);
void calculatetreatmentCharges(string &disease, int age, float &treatmentCost);
void PrintBill(string &name, int age, string &disease, string &doctor, string &roomType, int nurses, string &tests, float testcharges, float treatmentCost);
int main(){
string name,disease,doctor,roomType,nursesRequired,tests;
float testcharges=0, treatmentCost=0;
int age;
cout<<"-----Hospital Management System-----\n";
registerPatient(name,age,disease);
assignDoctor(disease,doctor);
assignRoom(disease,roomType,nursesRequired);
selectTests(tests,testcharges);
calculatetreatmentCharges(disease,age,treatmentCost);

printBill(name,age,disease,doctor,roomType,nursesRequired,tests,testcharges,treatmentCost);
}
//Function Definitions
void registerPatient(string &name,int &age, string &disease)
{
    cout<<"\n  Enter Patient Name";cin>>name;
    cout<<"\n Enter Patient Age";cin>>age;
    cout<<"\n Enter disease";cin>>disease;
}
void assignDoctor(string &disease, string &doctor)
{
    if(disease=="fever" || "cold")
        doctor="Dr. Sharma";
    else if(disease=="fracture")
        doctor="Dr. Mehta";
    else if(disease=="heart")
        doctor="Dr. Verma";
    else
        doctor="Dr. general";
}
void assignRoom(string &disease, string &roomType, int &nursesRequired)
{
    if(disease=="fracture")
    {
        roomType="Emergency";
        nursesRequired=2;
    }
    else
    {
        roomType="General";
        nursesRequired=1;
    }
}
void selectTests(string &tests, float &testcharges)
{
    char choice;
    cout<<"\n Do you want a blood test?(y/n):";
    cin>>choice;
    if(choice=='y')
    {
        tests+="Blood Test";
        testcharges+=500;
    }
    cout<<"Do you want an X-ray?(y/n)";
    cin>>choice;
    if(choice=='y')
    {
        tests+="X-Ray";
        testcharges+=1000;
    }
    cout<<"Do you want an MRI?(y/n)";
    cin>>choice;
    if(choice=='y')
    {
        tests+=MRI;
        testcharges+=3000;
    }
}
void calculatetreatmentCharges(string &disease,int age, float &treatmentCost)
{
    if(disease=="fever" || "cold")
    treatmentCost=1000;
    else if(disease=="heart")
        treatmentCost=1200;
    else if(disease=="fracture")
        treatmentcost=5000;
    else
        treatmentCost=1500;
    if(age>60)
        treatmentCost+=500;
}
void printBill(string &name, int age, string &disease, string &doctor, string &roomtype, int nurses, string &tests, float testcharges, float treatmentCost)
{
    float total=testcharges+treatmentCost;
    cout<<"\n---Final Bill-----\n";
    cout<<"Age"<<age<<"\n";
    cout<<"Disease"<<disease<<"\n";
    cout<<"Doctor Assigned"<<doctor<<"\n";
    cout<<"Room Type"<<roomType<<"\n";
    cout<<"Nurses Required"<<nurses<<"\n";
    cout<<"Test Charges: Rs."<<testcharges<<"\n";
    cout<<"Treatment Charges: Rs."<<treatmentCost<<"\n";
    cout<<"-----------------------------------";
    cout<<"Total Bill: Rs."<<total<<"\n";
}

