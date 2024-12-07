#include <iostream>
#include <cstring>
#include <conio.h>  // getch() for password
#include <fstream>
#include <sstream>
#include <windows.h>  //full screen model

using namespace std;

//patient login
string loggedInPatientUsername = "";
string loggedInPatientFirstName = "";
string loggedInPatientLastName = "";

//doctor login
string loggedInDoctorUsername = "";
string loggedInDoctorFirstName = "";
string loggedInDoctorLastName = "";

int mainMenu();     //print main menu
int Login(int menuNo);      //main menu opptions
int adminLogin();       //admin menu
void patientLogin();
//patient main menu and their choices
int patientLogin1(int pMenuNo);
int patientLogin2(int pMenuNo);
int patientLoginMenu();
//doctor menu
void doctorLogin();
int doctorLoginMenu();
//about us
void aboutUs();
//file handling functions
void addDoctor();   //add doctors
void viewDoctorDetails();   //admin task
void addAppoinment();       //add appointments
void getAppointment();      //view appointment
void updatePatientInformation();    //update patient details
void viewPatientDetails();  //view patient personal information
void viewPatientRecords();  //view patient records
void cancelAppointment();   //cancel appointment
void updatePationRecord();  //add patient records by doctor
void appointmentMark(); // mark appointment as complete
void doctorViewSchedule();  //doctors view their schedule
void viewPatients();    //admin view patient details
void accessPatientRecord(); //doctor access patient medical history


int main()
{
    //full screen
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    cout<<"\n";
    cout<<"\n           ****************************************************"<<endl;
    cout<<"\n                 Welcome To ABE Clinical Management System     "<<endl;
    cout<<"\n           ****************************************************"<<endl;

    mainMenu();

    return 0;
}

//Print the main menu
int mainMenu(){
    int menuNo;

    // Print main menu
    cout<<"\n\n\n";
    cout<<"                     ---------------------"<<endl;
    cout<<"                           Main Menu      "<<endl;
    cout<<"                     ---------------------"<<endl;
    cout<<"\n                   \t 1.Admin Login"<<endl;
    cout<<"                     \t 2.Patient Login"<<endl;
    cout<<"                     \t 3.Doctor Login"<<endl;
    cout<<"                     \t 4.About us"<<endl;
    cout<<"                     \t 5.Exit"<<endl;
    cout<<"\n                Enter your choice number:";
    cin>>menuNo;
    Login(menuNo);

    return menuNo;
}


// Display the main menu choice
        int Login(int menuNo){

                //admin menu
            if(menuNo == 1){
                string aUsername;
                string aPassword;
                char pw;

                cout<<"\n\n";
                cout<<"          Enter your User Name :";
                cin>>aUsername;
                cout<<"          Enter your Password  :";


                //hashed password
               while ((pw = getch()) != 13) {
                    if (pw == 8) {  // ASCII value of backspace
                        if (!aPassword.empty()) {
                            cout << "\b \b";  // Move the cursor back, print a space, move back again
                            aPassword.pop_back();
                        }
                    }
                    else {
                        aPassword.push_back(pw);
                        cout << '*';
                    }
                }

                if(aUsername == "abecadmin" && aPassword == "abec123"){

                    adminLogin();
                }
                else{
                    cout<<"\n\n";
                    cout<<"         Your User name or Password Invalid!"<<endl;
                    cout<<"         Please Try Again!!"<<endl;
                    return mainMenu();

                }

            }

            // choice 2 patient in main menu
             else if(menuNo == 2){
                    patientLoginMenu();
            }


            // choice 3 doctor in mainmenu
            else if(menuNo == 3){
                    doctorLogin();
            }

            else if(menuNo == 4){
                    system("cls");
                    int i;
                    cout<<"                                    -------------"<<endl;
                    cout<<"                                    |  About US |"<<endl;
                    cout<<"                                    -------------"<<endl;
                    aboutUs();
                    cout<<"      \n\nPlease Enter 1 and go to main menu:";
                    cin>>i;
                    if(i == 1){
                        system("cls");
                        return mainMenu();
                    }
                    else{
                        cout<<"     \nInvalid input please enter number 1:";
                        cin>>i;
                        return mainMenu();
                    }

              }


            // choice 3 in mainmenu
            else if(menuNo == 5){
                cout<<"\n\n\n";
                cout<<"      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                cout<<"        ~~~~~~~~~~ Thank You For Using ABEC Clinical Management System ~~~~~~~~~~"<<endl;
                cout<<"      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                return 0;
            }

            // invalid choice in mainmenu
            else{
                system("cls");
                cout<<"\n             Enter Invalid Number!"<<endl;
                cout<<"             Please Enter Valid Number (1-4)\n"<<endl;
                return mainMenu();
            }


            return 0;
        }


// admin menu
int adminLogin(){

        system("cls");
        int addNo;
        cout<<"\n"<<endl;
        cout<<"                     ---------------------------"<<endl;
        cout<<"                     |---- ABEC Admin Menu ----|"<<endl;
        cout<<"                     ---------------------------"<<endl;
        cout<<"\n                 \t 1.Patient Register"<<endl;
        cout<<"                   \t 2.Doctor Register"<<endl;
        cout<<"                   \t 3.Add doctor Schedule"<<endl;
        cout<<"                   \t 4.View Patient Details"<<endl;
        cout<<"                   \t 5.View Doctor Details"<<endl;
        cout<<"                   \t 6.Back to main menu"<<endl;

        cout<<"\n           Enter Your Choice Number :";
        cin>>addNo;

        if(addNo == 1){
            system("cls");
            patientLogin1(addNo);

             int no;
                int pMenuNo;
                cout<<"\n    Please Enter Number 1 to go back :";
                cin>>no;

                if(no == 1){
                    adminLogin();
                }
                else{
                    cout<<"   Invalid Number Please Enter Number 1:";
                    cin>>no;
                    adminLogin();
                }
        }

        else if(addNo == 2){
            system("cls");
            addDoctor();
            return adminLogin();
        }

        else if(addNo == 3){
            addAppoinment();
           return adminLogin();
        }

        else if(addNo == 4){
            viewPatients();

            //return statement
                int no;
                cout<<"\n    Please Enter Number 1 to go back :";
                cin>>no;

                if(no == 1){
                    return adminLogin();
                }
                else{
                    cout<<"   Invalid Number Please Enter Number 1:";
                    cin>>no;
                    return adminLogin();
                }
        }

        else if(addNo == 5){
            viewDoctorDetails();

            //return statement
                int no;
                cout<<"\n    Please Enter Number 1 to go back :";
                cin>>no;

                if(no == 1){
                    return adminLogin();
                }
                else{
                    cout<<"   Invalid Number Please Enter Number 1:";
                    cin>>no;
                    return adminLogin();
                }
        }

        else if(addNo == 6){
            system("cls");
            return mainMenu();
        }


        else{
            int adNo;
            cout<<"\n       Invalid Choice !!"<<endl;
            cout<<"\n       Please Enter Number 1:";
            cin>>adNo;
            if(adNo == 1){
                return adminLogin();
            }
            else{
                cout<<"\n       Please Enter Number 1 :";
                cin>>adNo;
                return adminLogin();
            }
        }


}


//patient main menu
int patientLoginMenu(){
                system("cls");
                int pMenuNo;
                    //int response;
                    cout<<"\n"<<endl;
                    cout<<"          -----------------------------"<<endl;
                    cout<<"          |------ Patient Login ------|"<<endl;
                    cout<<"          -----------------------------"<<endl;
                    cout<<"\n \t 1.Create a new user account"<<endl;
                    cout<<"   \t 2.Sign in to your user account"<<endl;
                    cout<<"   \t 3.Back to the main menu"<<endl;

                    cout << "\n     Enter your choice number:";
                    cin >> pMenuNo;


                        if (pMenuNo == 1){
                            system("cls");
                            patientLogin1(pMenuNo);//create new patient account

                            int response;
                            cout<<"\n\nPlease enter 1 and go to Patient login menu";
                            cout<<"\nThen you can enter number 2 and sign into your user account:";
                            cin>>response;

                            if(response == 1){
                                return patientLoginMenu();
                            }
                            else{
                                cout<<"\n\n  Invalid choice !!"<<endl;
                                cout<<"  Please Enter Number 1 :";
                                cin>>response;
                                return patientLoginMenu();
                            }

                        }

                        else if (pMenuNo == 2){
                            patientLogin();
                        }

                        else if (pMenuNo == 3) //sign in to patient account
                        {
                            system("cls");
                            return mainMenu(); // Go back to the main menu
                        }

                        else
                        {
                            int Mno;
                            cout << "\n         Enter Invalid Number !!" << endl;
                            cout << "         Please Enter Number 1 to go back:";
                            cin>>Mno;
                            if(Mno == 1){
                                return patientLoginMenu();
                            }
                            else{
                                cout<<"         Please Enter Number 1 :";
                                cin>>Mno;
                                return patientLoginMenu();
                            }
                        }

}


// choice 1 in patient login menu
//create a new patient account
int patientLogin1(int pMenuNo){
    //using for create a new patient.txt file
    /*fstream patientfile;
    patientfile.open("Patient Details.txt",std::ios::out);
    if(!patientfile){
        cout<<"File Creation Failed"<<endl;
    }
    else{
        cout<<"File creation successful"<<endl;
        patientfile.close();
    }*/

    ofstream patientfile("Patient Details.txt",ios::app);

    if(! patientfile.is_open()){
        cerr<<"Error opening file."<<endl;
        return patientLogin1(pMenuNo);
    }

        cout<<"\n          ````` Create a new user account ````` "<<endl;

        string pUsername;
        string pPassword;
        string fName;
        string lName;
        string pAddress;
        string pCono;
        string gender;
        int pAge;

        cin.ignore();
        cout<<"\n\t*Enter your first name\t:";
        cin>>fName;
        cout<<"\t*Enter your last name\t:";
        cin>>lName;
        cout<<"\t*Enter your address\t:";
        cin.ignore();
        getline(cin,pAddress);

        cout<<"\t*Enter contact number\n\t(eg-:07xxxxxxxx)\t:";
        getline(cin,pCono);

        while (pCono.length() != 10 ) {
            cout << "\t**Invalid contact number. Please enter a 10-digit number:";
            getline(cin,pCono);
        }

        cout<<"\t*Enter your gender \t:";
        getline(cin,gender);

        while(gender != "Female" && gender != "female" && gender != "Male" && gender != "male"){
            cout<<"\t**Invalid Input Please Enter Female or Male:";
            getline(cin,gender);
        }

        cout<<"\t*Enter your age \t:";
        cin>>pAge;

        while(pAge <= 0 || pAge >= 100){
            cout<<"\t**Invalid Age. Please Enter Valid Age:";
            cin>>pAge;
        }

        pUsername = fName;
        pPassword = fName + "0123";

        patientfile<<"\n";
        patientfile<<fName<<" "<<lName<<" "<<gender<<" "<<pAge<<" "<<pAddress<<" "<<pCono<<" "<<pUsername<<" "<<pPassword<<" ";

        cout<<"\n   HELLO "<<fName<<" "<<lName<<",";
        cout<<"\n   Your account create successful!!!!!!"<<endl;
        cout<<"\n    ***Your User name = "<<fName;
        cout<<"\n    ***Your Password  = "<<fName<<"0123";

        patientfile.close();

    }

// login to patient menu
void patientLogin() {
    string ufName;
    string P_pw;
    int pw;

    fstream patientfile;
    patientfile.open("Patient Details.txt", ios::in);

    cout << "\n \tEnter Your User name:";
    cin >> ufName;
    cout << "   \tEnter Your Password:";

    while ((pw = getch()) != 13) {
        if (pw == 8) { // ASCII value of backspace
            if (!P_pw.empty()) {
                cout << "\b \b"; // Move the cursor back, print a space, move back again
                P_pw.pop_back();
            }
        } else {
            P_pw.push_back(pw);
            cout << '*';
        }
    }

    bool loginSuccessful = false;

    string fName;
    if (!patientfile) {
        cout << "\t\t\t file cannot be open" << endl;
    } else {
        string record;
        while (getline(patientfile, record)) {
            if (record.empty()) {
                continue;
            }

            istringstream iss(record);
            string currentFName;
            string lName;

            if (iss >> currentFName) {
                // Additional extractions
                iss >> lName;

               if (currentFName == ufName && P_pw == currentFName + "0123") {
                    loggedInPatientUsername = currentFName;
                    loggedInPatientFirstName = fName;  // Assuming fName is the first name
                    loggedInPatientLastName = lName;   // Assuming lName is the last name
                    int pMenuNo;
                    loginSuccessful = true;
                    patientLogin2(pMenuNo);
                    break;
                }

            }
        }

        patientfile.close();

        // Invalid login part
        if (!loginSuccessful) {
            int pno;
            cout << "\n\n";
            cout << "         Your User name or Password Invalid!" << endl;
            cout << "         Please Try Again!!" << endl;
            cout << "         Please Enter Number 1 to Try Again:";
            cin >> pno;
            if (pno == 1) {
                patientLogin();
            } else {
                cout << "Please Enter Number 1:";
                cin >> pno;
                patientLogin();
            }
        }
    }
}


// choice 2 in patient login menu
//patient menu
int patientLogin2(int pMenuNo){

                            int pNo;
                            system("cls");
                            cout<<"\n\n"<<endl;
                            cout<<"            ````````````````````````````````````````````"<<endl;
                            cout<<"                 Welcome to ABEC Patient Login Page     "<<endl;
                            cout<<"            ````````````````````````````````````````````"<<endl;
                            cout<<"\n               \t1.View Medical Records";
                            cout<<"\n               \t2.Schedule Appointments";
                            cout<<"\n               \t3.Cancel Appointments";
                            cout<<"\n               \t4.Update Personal Information";
                            cout<<"\n               \t5.Back to the Main Menu"<<endl;

                            cout<<"\n     Please Enter Your Choice Number:";
                            cin>>pNo;

                            if(pNo == 1){
                                system("cls");
                                viewPatientRecords();
                            }

                            else if(pNo == 2){
                                system("cls");
                                getAppointment();
                                //return patientLogin2(pMenuNo);
                            }

                            else if(pNo == 3){
                                system("cls");
                                cancelAppointment();
                            }

                            else if(pNo == 4){
                                system("cls");
                                cout<<"\n\n";
                                cout<<"                ------------------------------------"<<endl;
                                cout<<"                | Update Your Personal Information |"<<endl;
                                cout<<"                ------------------------------------"<<endl;
                                updatePatientInformation();
                            }

                            else if(pNo == 5){
                                system("cls");
                                return mainMenu();
                            }


                        else{
                            int no;
                            cout << "\n\n           *Invalid Choice!.\n" << endl;
                            cout << "\n           Please Enter Number 1 to  go back:";
                            cin>>no;
                            if(no == 1){
                                return patientLogin2(pMenuNo);
                            }
                            else{
                                cout<<"         \nPlease Enter Number 1:";
                                cin>>no;
                                return patientLogin2(pMenuNo);
                            }
                        }
                        return 0;
                        //}

                        //}
                            /*cout<<"\n\n";
                            cout << "      User not found" << endl;
                            cout << "      Invalid Your User Name or Password"<<endl;
                            cout << "      Please Try Again"<<endl;*/

                    //}
                        //patientfile.close();
                        return patientLogin2(pMenuNo);
}


// patient menu no2
// add the appointment by patient
void getAppointment(){

        //open the schedule file for get doctors schedules
     ifstream schedulefile("Schedule Doctor Details.txt",ios::app);

        if(! schedulefile.is_open()){
            cerr<<"Error opening file."<<endl;
        return addDoctor();
        }


        cout<<"\n                           -----------------------------------------------------"<<endl;
        cout<<"                                                    Welcome !"<<endl;
        cout<<"                                         Make Your Appointment Here"<<endl;
        cout<<"                             -----------------------------------------------------"<<endl;
        cout<<"\n\n                                             Doctor Details "<<endl;
        cout<<"\n";

        cout<<"  \t==============================================================================================================="<<endl;
        cout<<"  \t  NO       \tDoctor Name          \tSubject         \tWork Day            \t Hours"<<endl;
        cout<<"  \t==============================================================================================================="<<endl;

        string record;
        while (getline(schedulefile, record)) {
        istringstream iss(record);
        string dID, dfName,dlName, dsubject, dWorkday, dofficeHours;

        iss >> dID >> dfName >>dlName >> dsubject >> dWorkday >> dofficeHours;
        cout<<"  \t "<<dID<<"      \t"<<dfName<<" "<<dlName<<"          \t"<<dsubject<<"         \t"<<dWorkday<<"            \t"<<dofficeHours<<endl;
        }


        string getdID;
        cout<<"\n\n    Enter NO to Make Appointment:";
        cin>>getdID;


                //print the patient details
                viewPatientDetails();

                // Reset the file position to the beginning
                schedulefile.clear();
                schedulefile.seekg(0);

                bool isValidID = false;

                    while (getline(schedulefile, record)) {
                    istringstream iss(record);
                    string dID, dfName,dlName, dsubject, dWorkday, dofficeHours,state;

                    if (iss >> dID) {
                           iss >> dfName >>dlName>> dsubject >> dWorkday >> dofficeHours>>state;

                    if (dID == getdID){
                        isValidID = true;
                        cout << "\t\t\t Doctor Name \t:\t" << dfName <<" " <<dlName<< endl;
                        cout << "\t\t\t Subject     \t:\t" << dsubject << endl;
                        cout << "\t\t\t Work Day    \t:\t" << dWorkday << endl;
                        cout << "\t\t\t Hours       \t:\t" << dofficeHours <<endl;
                        cout << "\t\t\t State       \t:\t" << "Upcoming...."<<endl;
                        cout<<"\n          -----------------------------------------------------------"<<endl;
                    }
                    }
                    }


                    if (!isValidID) {
                        cout << "\t\t\t *Invalid Doctor ID!!" << endl;
                        cout << "\t\t\t *Please Try Again " << endl;
                        return getAppointment();
                    }



                        // write the appointment details in the Patient Appointment file
                         ofstream patientAppointment("Patient Appointment File.txt",ios::app);

                        if(! patientAppointment.is_open()){
                            cerr<<"Error opening file."<<endl;
                            return getAppointment();
                        }

                        // Reset the file position to the beginning
                            schedulefile.clear();
                            schedulefile.seekg(0);

                        while (getline(schedulefile, record)) {
                        istringstream iss(record);
                        string  dID,dfName,dlName, dsubject, dWorkday, dofficeHours,state;

                            if (iss >> dID) {
                            iss >> dfName >>dlName>> dsubject >> dWorkday >> dofficeHours>>state;

                                if (getdID == dID){
                                    state = "Upcoming...";
                                    patientAppointment<<dfName<<" "<<dlName<<"    "<< dsubject <<"   "<< dWorkday <<"    "<< dofficeHours<<"  " << state<< "    ";
                                }

                            }

                        }

                            // Close the files
                            schedulefile.close();
                            patientAppointment.close();


    //return statement
    int no;
    int pMenuNo;
    cout<<"\n\n    Please Enter Number 1 to go back :";
    cin>>no;

    if(no == 1){
        patientLogin2(pMenuNo);
    }
    else{
        cout<<"   Invalid Number Please Enter Number 1:";
        cin>>no;
        patientLogin2(pMenuNo);
    }

}

//patient menu no2 sub function
//view patient details for print appointment
void viewPatientDetails() {
    fstream patientfile;
    patientfile.open("Patient Details.txt", ios::in);

    if (!patientfile) {
        cout << "\t\t\t file cannot be open" << endl;
    } else {
        string record;
        bool patientFound = false;

        while (getline(patientfile, record)) {
            if (record.empty()) {
                continue;
            }

            istringstream iss(record);
            string fName, lName, gender, pAge;

            if (iss >> fName) {
                // Additional extractions
                iss >> lName >> gender >> pAge;

                if (fName == loggedInPatientUsername) {
                    // Set a flag to indicate patient found
                    patientFound = true;

                    cout << "\n\n   Your Appointment Make Successful!" << endl;
                    cout << "\n\n";
                    cout << "         ------------------------------------------------------------" << endl;
                    cout << "                      ABEC Clinical Management System" << endl;
                    cout << "                                  Appointment" << endl;
                    cout << "         ------------------------------------------------------------" << endl;

                    cout << "\t\t\t Name        \t:\t" << fName << " " + lName << endl;
                    cout << "\t\t\t Gender      \t:\t" << gender << endl;
                    cout << "\t\t\t Age         \t:\t" << pAge << endl;
                }
            }
        }

        // Write to the file only if the patient is found
        if (patientFound) {
            ofstream patientAppointment("Patient Appointment File.txt", ios::app);

            if (!patientAppointment.is_open()) {
                cerr << "Error opening file." << endl;
                return getAppointment();
            }

            patientAppointment << loggedInPatientUsername << " ";

            patientAppointment.close();
        } else {
            // Patient not found
            cout << "\t\t\t *Your Name not found" << endl;
            cout << "\t\t\t *Sorry! Record unavailable" << endl;
        }
    }

    patientfile.close();
}


// doctor login
void doctorLogin() {
    string ufName;
    string P_pw;
    int pw;

    fstream doctorfile;
   doctorfile.open("Doctor Details.txt", ios::in);

    cout << "\n \tEnter Your User name:";
    cin >> ufName;
    cout << "   \tEnter Your Password:";

    while ((pw = getch()) != 13) {
        if (pw == 8) { // ASCII value of backspace
            if (!P_pw.empty()) {
                cout << "\b \b"; // Move the cursor back, print a space, move back again
                P_pw.pop_back();
            }
        } else {
            P_pw.push_back(pw);
            cout << '*';
        }
    }

    bool loginSuccessful = false;

    string fName;
    if (!doctorfile) {
        cout << "\t\t\t file cannot be open" << endl;
    } else {
        string record;
        while (getline(doctorfile, record)) {
            if (record.empty()) {
                continue;
            }

            istringstream iss(record);
            string DId, currentFName;
            string lName;

            if (iss >> DId >>currentFName) {
                // Additional extractions
                iss >> lName;

               if (currentFName == ufName && P_pw == currentFName + "5678") {
                    loggedInDoctorUsername = currentFName;
                    loggedInDoctorFirstName = fName;  // Assuming fName is the first name
                    loggedInDoctorLastName = lName;   // Assuming lName is the last name
                    int pMenuNo;
                    loginSuccessful = true;
                    doctorLoginMenu();
                    break;
                }

            }
        }

        doctorfile.close();

        // Invalid login part
        if (!loginSuccessful) {
            int pno;
            cout << "\n\n";
            cout << "         Your User name or Password Invalid!" << endl;
            cout << "         Please Try Again!!" << endl;
            cout << "         Please Enter Number 1 to Try Again:";
            cin >> pno;
            if (pno == 1) {
                mainMenu();
            } else {
                cout << "Please Enter Number 1:";
                cin >> pno;
                mainMenu();
            }
        }
    }
}


//doctor menu
            int doctorLoginMenu(){

                    int dNo;
                        system("cls");
                        cout<<"\n"<<endl;
                        cout<<"              ----------------------------"<<endl;
                        cout<<"              |------ Doctor Login ------|"<<endl;
                        cout<<"              ----------------------------"<<endl;
                        cout<<"\n            \t1.View Schedule"<<endl;
                        cout<<"              \t2.Access Patient Records"<<endl;
                        cout<<"              \t3.Update Patient Records"<<endl;
                        cout<<"              \t4.Mark Appointment as Complete"<<endl;
                        cout<<"              \t5.Back to the main menu"<<endl;
                        cout<<"\n       Enter your choice number:";
                        cin>>dNo;
                    if(dNo == 1){
                        doctorViewSchedule();
                    }

                    else if(dNo == 2){
                        accessPatientRecord();
                    }

                    else if(dNo == 3){
                        updatePationRecord();
                    }

                    else if(dNo == 4){
                        system("cls");
                        appointmentMark();
                    }

                    else if(dNo == 5){
                        system("cls");
                        return mainMenu();
                    }
                    else{
                        cout << "\n\n*Invalid Choice!.\n" << endl;
                        cout << "\n Please Enter Number 1 to Return to Doctor Menu:";
                        cin >>dNo;
                        system("cls");
                        return doctorLoginMenu();
                    }

            }


// admin task no2
// create a new doctor account by admin
void addDoctor(){

    //using for create a new .txt file
    /*fstream doctorfile;
    doctorfile.open("Doctor Details.txt",std::ios::out);
    if(!doctorfile){
        cout<<"File Creation Failed"<<endl;
    }
    else{
        cout<<"File creation successful"<<endl;
        doctorfile.close();
    }*/

    cout<<"\n\n";
    cout<<"       ++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"                 Add New Doctor Details          "<<endl;
    cout<<"       ++++++++++++++++++++++++++++++++++++++++++"<<endl;

    ofstream doctorfile("Doctor Details.txt",ios::app);

    if(! doctorfile.is_open()){
        cerr<<"Error opening file."<<endl;
        return addDoctor();
    }
        char response='\0';
        //get user inputs
        string dID;
        string dusername;
        string dpassword;
        string dfirstname;
        string dlastname;
        string dDOB;
        string daddress;
        string dcono;
        string MLN;
        string dsubject;
        string dWorkdays;
        string dofficeHours;

        do{
        cin.ignore();
        cout<<"\n  Enter Doctor ID:";
        getline(cin,dID);

        cout<<"  Enter Doctor First Name:";
        getline(cin,dfirstname);

        cout<<"  Enter Doctor Last Name:";
        getline(cin,dlastname);

        cout<<"  Enter Doctor Birthday(YYYY/MM/DD):";
        getline(cin,dDOB);

        cout<<"  Enter Doctor Address:";
        getline(cin,daddress);

        cout<<"  Enter Doctor Contact Number(07xxxxxxxx):";
        getline(cin,dcono);

        while (dcono.length() != 10 ) {
            cout << "\t\n  **Invalid contact number. Please enter a 10-digit number:";
            getline(cin,dcono);
        }

        cout<<"  Enter Doctor Medical License Number:";
        getline(cin,MLN);

        cout<<"  Enter Doctor Subject:";
        getline(cin,dsubject);

        cout<<"  Enter Doctor Work Days:";
        getline(cin,dWorkdays);

        cout<<"  Enter Doctor Working Hours:";
        getline(cin,dofficeHours);


        dusername = dfirstname;
        dpassword = dfirstname+"5678";


        //doctorfile<<"ID     First Name     Last Name     DOB     Address     Contact Number     MLN     Subject     Work Days     Hours     User name     Password";

        doctorfile<<dID<<" "<<dfirstname<<" "<<dlastname<<" "<<dDOB<<" "<<daddress<<" "<<dcono<<" "<<MLN<<" "<<dsubject<<" "<<dWorkdays<<" "<<dofficeHours<<" "<<dusername<<" "<<dpassword<<" ";

        doctorfile.close();


        cout<<"\n      ABEC admin,"<<endl;
        cout<<"     Dr."<<dfirstname<<" "<<dlastname<<" account create successful "<<endl;
        cout<<"     Dr."<<dfirstname<<" "<<dlastname<<"'s,"<<endl;
        cout<<"       *User name = "<<dusername<<endl;
        cout<<"       *Password  = "<<dpassword<<endl;

        cout<<"\n  Do you want to add new doctor details ?"<<endl;
        cout<<"  (If you enter 'N' you can return to the Admin menu)"<<endl;
        cout<<"  Please Enter Yes(Y/y) or No(N/n) :";
        cin>>response;
        }while (response == 'Y' || response == 'y');


}

// admin tasks no5
// view doctor details
void viewDoctorDetails() {

                    fstream doctorfile;
					doctorfile.open("Doctor Details.txt",ios::in);
					system("cls");

					cout<<endl;
					cout<<"             -----------------------------------------"<<endl;
					cout<<"                      View Doctor Details"<<endl;
					cout<<"             -----------------------------------------"<<endl;

                    string vdname;
                        cout<<"\n\n";
                        cout<<"   Enter Doctor Name:";
                        cin.ignore();
                        getline(cin,vdname);

					if(!doctorfile){
						cout<<"\t\t\t file cannot be open"<<endl;
					}

					else{
						string record;
						while(getline(doctorfile,record)){

							if (record.empty()) {
                            continue;
                            }

                            istringstream iss(record);
							string dID;
                            string dfirstname;
                            string dlastname;
                            string dDOB;
                            string daddress;
                            string dcono;
                            string MLN;
                            string dsubject;
                            string dWorkdays;
                            string dofficeHours;
							if (iss >> dID) {
                            // Additional extractions
                            iss >> dfirstname>>dlastname>>dDOB>>daddress>>dcono>>MLN>>dsubject>>dWorkdays>>dofficeHours;
								if (dfirstname + " " + dlastname == vdname){
                                    cout<<"\n\n";
									cout<<"\t\t\t Doctor ID              \t:\t"<<dID<<endl;
									cout<<"\t\t\t Doctor Name            \t:\t"<<dfirstname<<" " + dlastname<<endl;
									cout<<"\t\t\t Birthday               \t:\t"<<dDOB<<endl;
									cout<<"\t\t\t Address                \t:\t"<<daddress<<endl;
									cout<<"\t\t\t Contact Number         \t:\t"<<dcono<<endl;
									cout<<"\t\t\t Medical License Number \t:\t"<<MLN<<endl;
									cout<<"\t\t\t Subject                \t:\t"<<dsubject<<endl;
									cout<<"\t\t\t Work Days              \t:\t"<<dWorkdays<<endl;
									cout<<"\t\t\t Hours                  \t:\t"<<dofficeHours<<endl;

									return;
								}

                                }

						}

                        // ID not found
                        cout << "\t\t\t Doctor Name not found" << endl;
                        // Move the 'else' outside the 'while' loop
                        cout << "\t\t\t Sorry! Record unavailable" << endl;

            		}
            		doctorfile.close();

}


//admin task no3
// add appointment details to system by admin
void addAppoinment(){
    //using for create a new .txt file
    /*fstream schedulefile;
    schedulefile.open("Schedule Doctor Details.txt",std::ios::out);
    if(!schedulefile){
        cout<<"File Creation Failed"<<endl;
    }
    else{
        cout<<"File creation successful"<<endl;
        schedulefile.close();
    }*/
    system("cls");
     ofstream schedulefile("Schedule Doctor Details.txt",ios::app);

    if(! schedulefile.is_open()){
        cerr<<"Error opening file."<<endl;
        return addDoctor();
    }
        cout<<"\n";
        cout<<"          ++++++++++++++++++++++++++++++++++++++++++"<<endl;
        cout<<"                 Add New Schedule Appointment         "<<endl;
        cout<<"          ++++++++++++++++++++++++++++++++++++++++++"<<endl;

        char response ='\0';
        string dID;
        string dName;
        string dsubject;
        string dWorkday;
        string dofficeHours;

        do{
        cin.ignore();
        cout<<"\n  Enter Doctor ID:";
        getline(cin,dID);

        cout<<"  Enter Doctor Name:";
        getline(cin,dName);

        cout<<"  Enter Doctor Subject:";
        getline(cin,dsubject);

        cout<<"  Enter Doctor Work Day:";
        getline(cin,dWorkday);

        cout<<"  Enter Doctor Working Hours:";
        getline(cin,dofficeHours);


        schedulefile<<dID<<" "<<dName<<" "<<dsubject<<" "<<dWorkday<<" "<<dofficeHours;

        schedulefile.close();

        cout<<"\n    ++++ Appointment Schedule Add successful ++++"<<endl;
        cout<<"\n  Do you want to add new appointment details ?"<<endl;
        cout<<"  Please Enter Yes(Y/y) or No(N/n) :";
        cin>>response;
        }while (response == 'Y' || response == 'y');

}



//patient menu no4
//update the patients personal information
void updatePatientInformation() {
    // Open the file in input mode
    fstream patientfile("Patient Details.txt", ios::in);

    if (!patientfile) {
        cout << "\t\t\t File cannot be open" << endl;
    }
    else {
        // Create a temporary stream to store modified content
        ostringstream tempStream;

        string record;
        bool found = false;
        while (getline(patientfile, record)) {
            if (record.empty()) {
                continue;
            }

            istringstream iss(record);
            string fName;
            string lName;
            string gender;
            string pAge;
            string pAddress;
            string pCono;
            string username,password;

            if (iss >> fName) {
                // Additional extractions
                iss >> lName >> gender >> pAge >> pAddress >> pCono;

                if (fName == loggedInPatientUsername) {
                    found = true;
                    cout << "\t\t\t Name            \t:\t" << fName << " " + lName << endl;
                    cout << "\t\t\t Gender          \t:\t" << gender << endl;
                    cout << "\t\t\t Age             \t:\t" << pAge << endl;
                    cout << "\t\t\t Address         \t:\t" << pAddress << endl;
                    cout << "\t\t\t Contact Number  \t:\t" << pCono << endl;

                    // Collect new data
                    cout<<"\n\n\n";
                    cout << "         +++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << "                          Enter Your New Data" << endl;
                    cout << "         +++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
                     cout << "\n\n   What field do you want to update?" << endl;
                    cout << "\t\t\t 1.Name            " << endl;
                    cout << "\t\t\t 2.Gender          " << endl;
                    cout << "\t\t\t 3.Age             " << endl;
                    cout << "\t\t\t 4.Address         " << endl;
                    cout << "\t\t\t 5.Contact Number  " << endl;
                    string opt;
                    cout<<"\n";
                    cout << "     Please Enter Your Choice:";
                    cin >> opt;

                    if (opt == "1") {
                        cin.ignore();
                        cout << "\n\t Enter Your New First Name :";
                        getline(cin, fName);
                        cout << "\t Enter Your Last Last Name :";
                        getline(cin, lName);

                        username = fName;
                        password = fName + "0123";
                        cout << "        **Your User Name:" << username << endl;
                        cout << "        **Your Password:" << password << endl;
                    } else if (opt == "2") {
                        cout<<"\n";
                        cout << "\t Enter Your Gender :";
                        getline(cin, gender);

                        while (gender != "Female" && gender != "Male" && gender != "female" && gender != "male") {
                            cout << "\t**Invalid Input Please Enter Female or Male:";
                            getline(cin, gender);
                        }
                    } else if (opt == "3") {
                        cout<<"\n";
                        cout << "\t Enter Your New Age  :";
                        cin >> pAge;

                        /*while (pAge <= 0 || pAge >= 100) {
                            cout << "\t**Invalid Age. Please Enter Valid Age:";
                            cin >> pAge;
                        }*/
                    } else if (opt == "4") {
                        cin.ignore();
                        cout<<"\n";
                        cout << "\t Enter Your New Address  :";
                        getline(cin, pAddress);
                    } else if (opt == "5") {
                        cout<<"\n";
                        cout << "\t Enter Your New Contact Number  :";
                        getline(cin, pCono);

                        while (pCono.length() != 10) {
                            cout << "\t**Invalid contact number. Please enter a 10-digit number:";
                            getline(cin, pCono);
                        }
                    } else {
                        cout << "Invalid Number Please Enter (1-5):";
                        cin >> opt;
                        continue;  // Use continue to go back to the beginning of the loop
                    }

                    cout << "\n\n       Your Data Update Successful!" << endl;

                    // Update the record
                    username = fName;
                    password = fName + "0123";
                    tempStream << fName << " " << lName << " " << gender << " " << pAge << " " << pAddress << " " << pCono << " " << username << " " << password << " " << endl;
                } else {
                    // Write the record to the temporary stream
                    tempStream << record << endl;
                }
            }
        }

        // Close the input file
        patientfile.close();

        if (found) {
            // Reopen the file in output mode
            patientfile.open("Patient Details.txt", ios::out);

            // Write the modified content to the file
            patientfile << tempStream.str();

            // Close the output file
            patientfile.close();
        } else {
            // Name not found
            cout << "\t\t\t Your Name not found" << endl;
            // Move the 'else' outside the 'while' loop
        }
    }

    //return statement
    int no;
    int pMenuNo;
    cout<<"\n    Please Enter Number 1 to go back :";
    cin>>no;

    if(no == 1){
        patientLogin2(pMenuNo);
    }
    else{
        cout<<"   Invalid Number Please Enter Number 1:";
        cin>>no;
        patientLogin2(pMenuNo);
    }
}


//patient menu no1
//view patient personal details and appointment details
void viewPatientRecords(){

                        fstream patientfile;
                        patientfile.open("Patient Details.txt", ios::in);
                        cout<<"\n\n";
                        cout<<"                    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
                        cout<<"                              View Your Personal Information & Appointments"<<endl;
                        cout<<"                    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;

                        if (!patientfile) {
                            cout << "\t\t\t file cannot be open" << endl;
                        }
                        else {

                        bool found = false;
						string record;
						while(getline(patientfile,record)){

							if (record.empty()) {
                            continue;
                            }

                            istringstream iss(record);
							string fName;
                            string lName;
                            string gender;
                            string pAge;
                            string pAddress;
                            string pCono;

							if (iss >> fName) {
                                // Additional extractions
                                iss >> lName >> gender >> pAge >> pAddress >> pCono;

                            if (fName == loggedInPatientUsername) {
                                found = true;
                                cout << "\n";
                                cout << "                    ------------------------------------------------------------------" << endl;
                                cout << "                                         Hello!! "<<fName<<","<<endl;
                                cout << "                                    Personal Data Information " << endl;
                                cout << "                    ------------------------------------------------------------------" << endl;
                                cout << "\t\t\t Name            \t:\t" << fName << " " + lName << endl;
                                cout << "\t\t\t Gender          \t:\t" << gender << endl;
                                cout << "\t\t\t Age             \t:\t" << pAge << endl;
                                cout << "\t\t\t Address         \t:\t" << pAddress << endl;
                                cout << "\t\t\t Contact Number  \t:\t" << pCono << endl;

                            }

						}

            		}
            		patientfile.close();

            		fstream patientAppointment;
                        patientAppointment.open("Patient Appointment File.txt", ios::in);


                        if (!patientAppointment) {
                            cout << "\t\t\t file cannot be open" << endl;
                        }
                        else {

                                cout << "\n\n";
                                cout << "                    --------------------------------------------------------" << endl;
                                cout << "                                 Appointment Information " << endl;
                                cout << "                    --------------------------------------------------------" << endl;


                        bool found = false;
						string record;
						while(getline(patientAppointment,record)){

							if (record.empty()) {
                            continue;
                            }

							istringstream iss(record);
                            string getFname, dfName,dlName, dsubject, dWorkday, dofficeHours, state;

                            if (iss >> getFname) {
                                // Read the entire line after the first name into dName
                                //getline(iss, dName, '\t');

                                // Now, read the remaining fields
                                iss >> dfName>>dlName>>dsubject >> dWorkday >> dofficeHours >> state;

                            if (getFname == loggedInPatientUsername) {
                                found = true;
                                if(state != "Completed" && state != "Cancel"){
                                    state = "Upcoming ...";
                                }

                                cout << "\t\t\t Doctor Name     \t:\t" << dfName <<" "<<dlName<< endl;
                                cout << "\t\t\t Subject         \t:\t" << dsubject << endl;
                                cout << "\t\t\t Date            \t:\t" << dWorkday << endl;
                                cout << "\t\t\t Time            \t:\t" << dofficeHours << endl;
                                cout << "\t\t\t State           \t:\t" << state <<endl;
                                cout << "\n";
                                cout << "                    --------------------------------------------------------" << endl;

                            }
						}
            		}
            		if(found == false){
                        cout<<"                               You have no appointments"<<endl;
            		}
                }
                patientAppointment.close();
            }

            fstream patientRecords;
    patientRecords.open("Patient Records.txt", ios::in);

    if (!patientRecords) {
        cout << "\t\t\t file cannot be open" << endl;
    } else {
        cout << "\n\n";
        cout << "                    --------------------------------------------------------" << endl;
        cout << "                                       Medical History " << endl;
        cout << "                    --------------------------------------------------------" << endl;

        bool found = false;
        string record;
        while (getline(patientRecords, record)) {
            if (record.empty()) {
                continue;
            }

            istringstream iss(record);
            string pFname,dname,pLname, disease, medicine, recomands;

            if (iss >> dname>>pFname>>pLname>>disease >> medicine) {
                getline(iss, recomands);


                if (pFname == loggedInPatientUsername) {
                    found = true;

                    cout << "\t\t\t Disease     \t:\t" << disease << endl;
                    cout << "\t\t\t medicine    \t:\t" << medicine << endl;
                    cout << "\t\t\t Recommends  \t:\t" << recomands << endl;
                    cout << "                    --------------------------------------------------------" << endl;
                }
            }
        }

        if (!found) {
            cout << "                               You have no medical history" << endl;
        }
        patientRecords.close();
    }

    //return statement
    int no;
    int pMenuNo;
    cout<<"\n       Please Enter Number 1 to go back :";
    cin>>no;

    if(no == 1){
        patientLogin2(pMenuNo);
    }
    else{
        cout<<"   Invalid Number Please Enter Number 1:";
        cin>>no;
        patientLogin2(pMenuNo);
    }
}

//patient menu no3
//cancel the appointment
void cancelAppointment() {
    ifstream patientAppointmentIn("Patient Appointment File.txt");
    ofstream tempOut("temp.txt");

    cout << "\n\n";
    cout << "       ------------------------------------------------------" << endl;
    cout << "                  Cancel Your Appointment" << endl;
    cout << "       ------------------------------------------------------" << endl;

    if (!patientAppointmentIn || !tempOut) {
        cout << "\t\t\t File cannot be opened." << endl;
        return;
    }

    string record;
    bool deleted = false;

    while (getline(patientAppointmentIn, record)) {
        if (record.empty()) {
            continue;
        }

        istringstream iss(record);
        string getFname, dfName,dlName, dsubject, dWorkday, dofficeHours, state;

        // Extract the first column (getFname)
        if (iss >> getFname) {
            // Additional extractions
            iss >> dfName>>dlName >> dsubject >> dWorkday >> dofficeHours >> state;

            if (getFname == loggedInPatientUsername && state == "Upcoming...") {
                cout << "\n\n   Is this your appointment?" << endl;
                cout << "\n";
                cout << "      \tYour Name      \t:\t" << getFname << endl;
                cout << "      \tDoctor Name    \t:\t" << dfName<<" "<<dlName << endl;
                cout << "      \tDoctor Subject \t:\t" << dsubject << endl;
                cout << "      \tDate           \t:\t" << dWorkday << endl;
                cout << "      \tTime           \t:\t" << dofficeHours << endl;
                cout << "      \tState          \t:\t" << state << endl;
                cout << "\n\n";
                cout << "            Do you want to cancel your appointment" << endl;
                cout << "            (Please enter 'Y' or 'y'): ";
                char dresponse;
                cin >> dresponse;

                if (dresponse == 'Y' || dresponse == 'y') {
                    // Update the state
                    state = "Cancel";
                    deleted = true;
                    cout << "       ** **Appointment canceled successfully." << endl;
                } else {
                    // If the user chooses not to cancel, keep the original state
                    cout << "   Appointment not canceled." << endl;
                }
            }
        }

        // Append the modified record to the temp file
        tempOut << getFname << " " << dfName<<" " <<dlName<< " " << dsubject << " " << dWorkday << " " << dofficeHours << " " << state << endl;
    }

    // Close the input and output files
    patientAppointmentIn.close();
    tempOut.close();

    // If at least one appointment was found and processed, set deleted to true
    if (deleted) {
        // Remove the original file
        remove("Patient Appointment File.txt");
        // Rename the temp file to the original file
        rename("temp.txt", "Patient Appointment File.txt");
    } else if (!deleted) {
        cout << "Appointment not found for the given name." << endl;
    }

    // Return statement
    int no;
    int pMenuNo;
    cout << "\n    Please Enter Number 1 to go back :";
    cin >> no;

    if (no == 1) {
        patientLogin2(pMenuNo);
    } else {
        cout << "   Invalid Number Please Enter Number 1:";
        cin >> no;
        patientLogin2(pMenuNo);
    }
}

//doctor menu no3
//add patient records
void updatePationRecord(){

    //using for create a new patient records.txt file
    /*fstream recordfile;
    recordfile.open("Patient Records.txt",std::ios::out);
    if(!recordfile){
        cout<<"File Creation Failed"<<endl;
    }
    else{
        cout<<"File creation successful"<<endl;
        recordfile.close();
    }*/

    ofstream recordfile("Patient Records.txt",ios::app);

    if(! recordfile.is_open()){
        cerr<<"Error opening file."<<endl;
        return updatePationRecord();
    }
    system("cls");

    cout<<"\n";
    cout<<"           ++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"                          Add Patient Records"<<endl;
    cout<<"           ++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

    string pName;
    string disease;
    string medicine;
    string recommendations;

    cout<<"\n\n";
    cin.ignore();
    cout<<"       Enter Patient Name:";
    getline(cin,pName);
    cout<<"       Enter Patient Disease:";
    getline(cin,disease);
    cout<<"       Enter Prescribed Medications:";
    getline(cin,medicine);
    cout<<"       Enter Any Additional Recommendations:";
    getline(cin,recommendations);

    recordfile <<loggedInDoctorUsername<<" "<<pName<<" "<<disease<<" "<<medicine<<" "<<recommendations;

    cout<<"\n\n      Patient Record Add Successful!"<<endl;

    //recordfile<<endl;
    recordfile.close();

    //return statement
    int no;
    cout<<"\n    Please Enter Number 1 to go back :";
    cin>>no;

    if(no == 1){
        doctorLoginMenu();
    }
    else{
        cout<<"   Invalid Number Please Enter Number 1:";
        cin>>no;
        doctorLoginMenu();
    }

}


//doctor menu no4
// mark appointment as complete
void appointmentMark() {
    ifstream patientAppointment("Patient Appointment File.txt");
    ofstream tempOut("temp.txt");

    cout << "\n\n";
    cout << "           ------------------------------------------------------" << endl;
    cout << "                       Mark Appointment as Complete" << endl;
    cout << "           ------------------------------------------------------" << endl;

    if (!patientAppointment || !tempOut) {
        cout << "\t\t\t File cannot be opened." << endl;
        return;
    }

    string record;
    bool patientFound = false;
    string state; // Move the declaration outside the loop

    string pfName;
    cout<<"\n";
    cout << "             Enter Patient Name: ";
    cin >> pfName;

    string fName, dfName, dlName, dsubject, dWorkday, dofficeHours;
    while (getline(patientAppointment, record)) {
        if (record.empty()) {
            continue;
        }

        istringstream iss(record);

        if (iss >> fName) {
            // Additional extractions
            iss >> dfName >> dlName >> dsubject >> dWorkday >> dofficeHours >> state;

            if (fName == pfName && state == "Upcoming..." && dfName == loggedInDoctorUsername) {
                patientFound = true;
                cout<<"\n\n";
                cout << "      \tPatient Appointment Details," << endl;
                cout<<"\n";
                cout << "      \tPatient First Name\t:\t " << fName << endl;
                cout << "      \tDoctor Name       \t:\t " << dfName << " " << dlName << endl;
                cout << "      \tDoctor Subject    \t:\t " << dsubject << endl;
                cout << "      \tDate              \t:\t " << dWorkday << endl;
                cout << "      \tTime              \t:\t " << dofficeHours << endl;
                cout << "      \tState             \t:\t " << state << endl;

                char response;
                cout<<"\n";
                cout << "      Do you want to complete this appointment? (Y/N): ";
                cin >> response;

                if (response == 'Y' || response == 'y') {
                    // Update the state
                    state = "Complete";
                    cout<<"\n\n";
                    cout << "       Appointment marked as complete." << endl;
                } else {
                    cout<<"\n\n";
                    cout << "       Appointment not marked as complete." << endl;
                }
            }
        }

        // Append the modified record to the temp file
        tempOut << fName << " " << dfName << " " << dlName << " " << dsubject << " " << dWorkday << " " << dofficeHours << " " << state << endl;
    }

    // Close the input and output files
    patientAppointment.close();
    tempOut.close();

    // If at least one appointment was found and processed, set deleted to true
    if (patientFound) {
        // Remove the original file
        remove("Patient Appointment File.txt");
        // Rename the temp file to the original file
        rename("temp.txt", "Patient Appointment File.txt");
    } else {
        cout << "Appointment not found for the given name." << endl;
    }

    // Return statement
    int no;
    cout << "\n     Please Enter Number 1 to go back: ";
    cin >> no;

    if (no == 1) {
        doctorLoginMenu();
    } else {
        cout << "       Invalid Number. Returning to the main menu." << endl;
        doctorLoginMenu();
    }
}

//doctor menu no 1
// doctors view their schedule
void doctorViewSchedule() {

    ifstream patientAppointment("Patient Appointment File.txt");
    system("cls");


    cout<<"           ----------------------------------------"<<endl;
    cout<<"                     View Your Schedule"<<endl;
    cout<<"           ----------------------------------------"<<endl;

    if (!patientAppointment.is_open()) {
        cout << "\t\t\t File cannot be open" << endl;
    } else {
        bool found = false;
        string record;
        while (getline(patientAppointment, record)) {

            if (record.empty()) {
                continue;
            }

            istringstream iss(record);
            string fName, dName,dlname, dsubject, dWorkday, dofficeHours, state;

            if (iss >> fName) {
                // Additional extractions
                iss >> dName >>dlname >> dsubject >> dWorkday >> dofficeHours >> state;

                if (dName == loggedInDoctorUsername && state != "Complete") {

                        int pcount;
                        int pncount=0;

                        pncount = pcount +1;
                        pcount = pncount;

                    found = true;

                    // Open patient information file
                    ifstream patientfile("Patient Details.txt");

                    if (!patientfile.is_open()) {
                        cout << "\t\t\t File cannot be open" << endl;
                    } else {
                        bool patientFound = false;
                        string patientRecord;
                        while (getline(patientfile, patientRecord)) {


                            if (patientRecord.empty()) {
                                continue;
                            }

                            istringstream patientIss(patientRecord);
                            string patientFName, patientLName, gender, pAge, pAddress, pCono;
                            if (patientIss >> patientFName) {
                                // Additional extractions
                                patientIss >> patientLName >> gender >> pAge >> pAddress >> pCono;
                                if (patientFName == fName) {
                                    patientFound = true;

                                  cout << "Number of Patient:"<<pcount<<endl;
                                    cout << "\n";
                                    cout << "\t\t  ......................................................................"<<endl;
                                    cout << "\t\t\t Patient Name      \t:\t" << patientFName << " " + patientLName << endl;
                                    cout << "\t\t\t Gender            \t:\t" << gender << endl;
                                    cout << "\t\t\t Age               \t:\t" << pAge << endl;
                                    cout << "\t\t\t Address           \t:\t" << pAddress << endl;
                                    cout << "\t\t\t Contact Number    \t:\t" << pCono << endl;

                                }
                            }
                        }

                        patientfile.close();
                    }

                    cout << "\t\t\t Doctor Name        \t:\t" << dName<<" "<<dlname<< endl;
                    cout << "\t\t\t Doctor Subject     \t:\t" << dsubject << endl;
                    cout << "\t\t\t Date               \t:\t" << dWorkday << endl;
                    cout << "\t\t\t Time               \t:\t" << dofficeHours << endl;
                    cout << "\t\t\t State              \t:\t" << state << endl;
                    cout << "\t\t  ......................................................................"<<endl;
                }
            }
        }

        if (!found) {
            cout << "\n\t\t\t Invalid Name." << endl;
            cout << "\n\t\t\t No upcoming appointments." << endl;
        }

        patientAppointment.close();
    }
                //return statement
                int no;
                cout<<"\n    Please Enter Number 1 to go back :";
                cin>>no;

                if(no == 1){
                    doctorLoginMenu();
                }
                else{
                    cout<<"   Invalid Number Please Enter Number 1:";
                    cin>>no;
                    doctorLoginMenu();
                }
}

// doctor menu no2
//access patient records
void accessPatientRecord(){
                    fstream recordfile("Patient Records.txt");
					system("cls");
					cout<<endl;
					cout<<"             ----------------------------------------------------"<<endl;
					cout<<"                          Access Patient Records"<<endl;
					cout<<"             ----------------------------------------------------"<<endl;


                    string pfname;
                    cout<<"\n\n";
                        cout<<"             Enter Patient Name:";
                        cin.ignore();
                        getline(cin,pfname);

					if(!recordfile){
						cout<<"\t\t\t file cannot be open"<<endl;
					}

						string record;
						bool patientFound = false;
						while(getline(recordfile,record)){

							if (record.empty()) {
                            continue;
                            }

                            istringstream iss(record);
							string pfName,plName, disease, medicine, recommendations, dname;

							if (iss >> dname>> pfName >> plName >> disease >> medicine) {
                                // Extract the remaining part of the line as recommendations
                                getline(iss, recommendations);


								if (dname == loggedInDoctorUsername && pfName + " " + plName == pfname){
                                    patientFound = true;
									//cout<<"\t\t\t Patient Name          \t:\t"<<pName<<endl;
									cout<<"\t\t\t Disease               \t:\t"<<disease<<endl;
									cout<<"\t\t\t Prescribed Medications\t:\t"<<medicine<<endl;
									cout<<"\t\t\t Recommends            \t:\t"<<recommendations<<endl;
									break;
								}

                                }

						}

                        if (!patientFound) {
                            cout << "\t\t\t Patient Name not Found!" << endl;
                            cout << "\t\t\t Sorry! Record unavailable" << endl;
                        }

            		recordfile.close();

                            //return statement
                            int no;
                            cout<<"\n    Please Enter Number 1 to go back :";
                            cin>>no;

                            if(no == 1){
                                doctorLoginMenu();
                            }
                            else{
                                cout<<"   Invalid Number Please Enter Number 1:";
                                cin>>no;
                                doctorLoginMenu();
                            }

}

// admin tasks no4
// view Patient details
void viewPatients() {

                    fstream patientfile;
					patientfile.open("Patient Details.txt", ios::in);
					system("cls");
					cout<<endl;
					cout<<"             ----------------------------------------------------"<<endl;
					cout<<"                          View Patient Details"<<endl;
					cout<<"             ----------------------------------------------------"<<endl;


                    string pfname;
                    cout<<"\n\n";
                        cout<<"      Enter Patient Name:";
                        cin.ignore();
                        getline(cin,pfname);

					if(!patientfile){
						cout<<"\t\t\t file cannot be open"<<endl;
					}

					else{
						string record;
						while(getline(patientfile,record)){

							if (record.empty()) {
                            continue;
                            }

                            istringstream iss(record);
							string fName;
                            string lName;
                            string gender;
                            string pAge;
                            string pAddress;
                            string pCono;

							if (iss >> fName) {
                                // Additional extractions
                                iss >> lName >> gender >> pAge >> pAddress >> pCono;


								if (fName + " " + lName == pfname){
                                    cout<<"\n\n";
									cout<<"\t\t\t Patient Name    \t:\t"<<fName<<" " + lName<<endl;
									cout<<"\t\t\t Gender          \t:\t"<<gender<<endl;
									cout<<"\t\t\t Age             \t:\t"<<pAge<<endl;
									cout<<"\t\t\t Address         \t:\t"<<pAddress<<endl;
									cout<<"\t\t\t Contact Number  \t:\t"<<pCono<<endl;

									return;
								}

                                }

						}

                        // Name not found
                        cout << "\t\t\t Patient Name not Found!" << endl;
                        cout << "\t\t\t Sorry! Record unavailable" << endl;

            		}
            		patientfile.close();

}

//main menu no4
//about the system
void aboutUs(){

        ifstream aboutfile("about us.txt",ios::app);

        if(! aboutfile.is_open()){
            cerr<<"Error opening file."<<endl;
        return aboutUs();
        }

        string record;
        while (getline(aboutfile, record)) {
        cout << record << endl;
    }


        aboutfile.close();

}


