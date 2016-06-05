#include "main.h"

//MainWindow Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    //Creates individual Writer objects on heap from data file.
    std::string dummy; std::string person_name; std::string first_name; std::string last_name; int person_institution_number; std::string person_years_of_life; std::string person_position_in_institution; std::string person_geographic_location; std::string person_circle_of_friends; std::string person_alive_or_dead; std::string person_strength_string; std::vector<int> individual_strength; std::string person_multiplicity_string; std::vector<std::string> person_multiplicity;

    std::ifstream fin;
    fin.open("Data1.txt");

    while (fin >> dummy >> person_name >> person_institution_number >> person_years_of_life >> person_position_in_institution >> person_geographic_location >> person_circle_of_friends >> person_alive_or_dead >> person_strength_string >> person_multiplicity_string) {

        individual_strength.clear();
        person_multiplicity.clear();

        int location = person_name.find('_');
        first_name = person_name.substr(0, location);
        last_name = person_name.substr(location + 1, person_name.size());

        person_name = first_name + " " + last_name;


        // Converting Position in Institution to Value
        std::string temp = person_position_in_institution;
        if (temp != "None") {
            if (temp == "1a") {
                person_position_in_institution = "Gorky Literary Institute Professor";
            }
            else if (temp == "3f") {
                person_position_in_institution = "Leningrad Branch of Detgiz Publishing House Author";
            }
            else if (temp == "2d") {
                person_position_in_institution = "\"Youth\" Journal Influential Figure";
            }
            else if (temp == "1a2d4e") {
                person_position_in_institution = "Gorky Literary Institute Professor \nMoscow Children's Section Editor \n\"Youth\" Journal Influential Figure";
            }
            else if (temp == "3e") {
                person_position_in_institution = "Leningrad Branch of Detgiz Publishing House Editor";
            }
            else if (temp == "2c") {
                person_position_in_institution = "\"Youth\" Journal Editorial Board";
            }
            else if (temp == "2c3b") {
                person_position_in_institution = "Leningrad Branch of Detgiz Publishing House Editor-in-Chief \n\"Youth\" Journal Editorial Board";
            }
            else if (temp == "2b") {
                person_position_in_institution = "\"Youth\" Journal Editor-in-Chief";
            }
        }


        for (size_t i = 0, n = person_strength_string.size(); i < n; ++i) {
            char convertee = person_strength_string[i];
            int b;

            // Converting char to string
            std::stringstream aa;
            std::string a;
            aa << convertee;
            aa >> a;

            // Converting string to int
            std::stringstream bb;
            bb << a;
            bb >> b;

            // b = convert_char(convertee);
            individual_strength.push_back(b);
        }


        for (size_t i = 0, n = person_multiplicity_string.size(); i < n; ++i) {
            char convertee = person_multiplicity_string[i];
            std::string value;

            switch (convertee) {
            case 'a': value = "Acquaintances";
                break;
            case 'b': value = "Friendship 1";
                break;
            case 'c': value = "Friendship 2";
                break;
            case 'd': value = "Friendship 3";
                break;
            case 'e': value = "Family";
                break;
            case 'f': value = "Memorial";
                break;
            case 'g': value = "Assistance to young authors";
                break;
            case 'h': value = "Professional 1";
                break;
            case 'i': value = "Professional 2";
                break;
            case 'j': value = "Master";
                break;
            case 'k': value = "Neighboring";
                break;
            case 'l': value = "Polemic";
                break;
            case 'm': value = "Common involvement in social activism";
                break;
            case 'n': value = "Friendship 3 + Professional 1";
                break;
            case 'o': value = "Acquaintances + Professional 1";
                break;
            case 'p': value = "Friendship 1 + Professional 1";
                break;
            case 'q': value = "Friendship 1 + Professional 2 + Common involvement in social activism";
                break;
            case 'r': value = "Friendship 1 + Professional 2";
                break;
            case 's': value = "Assistance to young authors + Professional 2";
                break;
            case 't': value = "Friendship 2 + Professional 2";
                break;
            case 'u': value = "Family + Professional 2";
                break;
            case 'v': value = "Professional 2 + Master";
                break;
            case 'w': value = "Professional 1 + Neighboring";
                break;
            case 'x': value = "Professional 1 + Polemic";
                break;
            case 'y': value = "Professional 2 + Common involvement in social activism";
                break;
            case 'z': value = "Family + Common involvement in social activism";
                break;
            case '#': value = "None";
                break;


            default:;
                break;
            }

            person_multiplicity.push_back(value);
        }


        Writer* writer = new Writer(person_name, person_institution_number, person_years_of_life, person_position_in_institution, person_geographic_location, person_circle_of_friends, person_alive_or_dead, individual_strength, person_multiplicity);

        Writers.push_back(writer); //add writers to the Points class object Writers

    }
    fin.close();

    createActions(); //creates actions for the items in the file and view menus

    setWindowTitle(tr("Soviet Children's Writers Network"));

}

//  PUBLIC SLOTS

//List Item Clicked Function
void MainWindow::listItemClicked(QListWidgetItem * item){
    std::string listItemText = item->text().toStdString();
    int ID = Writers.find_name(listItemText);
    createWriterProfile(ID);
}

//Create Dock Windows Function
void MainWindow::createDockWindows(){
    QDockWidget* dock = new QDockWidget(tr("Writers"));

    //initialize writerList and add writers
    writerList = new QListWidget(dock);
    writerList->addItems(QStringList()
                         << "Alexander Raskin"
                         << "Alexander Sharov"
                         << "Alexandra Brushtein"
                         << "Alexey Panteleev"
                         << "Anatoly Alexin"
                         << "Benedict Sarnov"
                         << "Boris Zhitkov"
                         << "Evgeny Shvartz"
                         << "Frida Vigdorova"
                         << "Georgy Belyh"
                         << "Iosif Dik"
                         << "Konstantin Paustovsky"
                         << "Korney Chukovsky"
                         << "Leonid Panteleev"
                         << "Lev Kassil"
                         << "Lidia Chukovskaya"
                         << "Lubov Kabo"
                         << "Maria Prilezhaeva"
                         << "Max Bremener"
                         << "Nora Gal"
                         << "Samuil Marshak"
                         << "Susanna Georgievskaya"
                         << "Tamara Gabbe"
                         << "Valentin Kataev"
                         << "Yakov Akim"
                         << "Yuri Sotnik"
                         << "Yuri Trifonov");

    dock->setWidget(writerList);
    addDockWidget(Qt::LeftDockWidgetArea, dock); //aligns dock to the left

    connect(writerList,SIGNAL(itemClicked(QListWidgetItem*)),this, SLOT(listItemClicked(QListWidgetItem*)));
}

//Show All Connections Function
void MainWindow::showAllConnections(){
    mode = 0;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Both Circles Function
void MainWindow::showBothCircles(){
    mode = 1;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Women Circle Function
void MainWindow::showWomenCircle(){
    mode = 2;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Men Circle Function
void MainWindow::showMenCircle(){
    mode = 3;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Acquaintance Function
void MainWindow::showAcquaintance(){
    mode = 4;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Friendship 1 Function
void MainWindow::showFriendship1(){
    mode = 5;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Friendship 2 Function
void MainWindow::showFriendship2(){
    mode = 6;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Friendship 3 Function
void MainWindow::showFriendship3(){
    mode = 7;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Family Function
void MainWindow::showFamily(){
    mode = 8;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Memorial Function
void MainWindow::showMemorial(){
    mode = 9;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Assistance Function
void MainWindow::showAssistance(){
    mode = 10;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Professional 1 Function
void MainWindow::showProfessional1(){
    mode = 11;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Professional 2 Function
void MainWindow::showProfessional2(){
    mode = 12;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Master-Disciple Function
void MainWindow::showMasterDisciple(){
    mode = 13;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Neighboring Function
void MainWindow::showNeighboring(){
    mode = 14;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Polemic Function
void MainWindow::showPolemic(){
    mode = 15;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Common Involvement Function
void MainWindow::showCommonInvolvement(){
    mode = 16;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Strength 1 Function
void MainWindow::showStrength1(){
    mode = 44;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Strength 2 Function
void MainWindow::showStrength2(){
    mode = 45;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Strength 3 Function
void MainWindow::showStrength3(){
    mode = 46;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Strength 4 Function
void MainWindow::showStrength4(){
    mode = 47;
    MainWindow::paintEvent(inputEvent);
    update();
}

//Show Strength 5 Function
void MainWindow::showStrength5(){
    mode = 48;
    MainWindow::paintEvent(inputEvent);
    update();
}



//PUBLIC MEMBER FUNCTIONS

//Create Writer Profile Function
void MainWindow::createWriterProfile(int ID){
    QString firstNameString = QString::fromStdString(Writers.get_first_name(ID)); //get writer's first name from Points class object Writers
    QString lastNameString = QString::fromStdString(Writers.get_last_name(ID)); //get writer's last name from Points class object Writers
    QLabel* name = new QLabel(firstNameString + " " + lastNameString); //make label for writer's name

    QString yearsOfLifeString = QString::fromStdString(Writers.get_years_of_life(ID)); //get writer's years of life from Points class object Writers
    QLabel* yearsOfLife = new QLabel(yearsOfLifeString); //make label for years of life

    QString geographicLocationString = QString::fromStdString(Writers.get_geographic_location(ID)); //get writer's geographic location from Points class object Writers
    QLabel* geographicLocation = new QLabel(geographicLocationString); //make label for geographic location

    QLabel* institutionLabel = new QLabel("Institution(s): ");
    int institutionNumber = Writers.get_institution_number(ID); //get institution number from Points class object Writers
    QString institutionString = QString::fromStdString(Writers.institution_number_to_string(institutionNumber)); //convert institution number to QString of names of institutions
    QLabel* institution = new QLabel(institutionString); //create label for institution name(s)

    //create a horizonatal layout for Institution label and the names of the institutions
    QHBoxLayout* institutionLayout = new QHBoxLayout;
    institutionLayout->addWidget(institutionLabel);
    institutionLayout->addWidget(institution);
    institutionLayout->setAlignment(Qt::AlignLeft);

    QLabel* positionLabel = new QLabel("Position in Institution: ");
    QString positionString = QString::fromStdString(Writers.get_position_in_institution(ID));//convert position in institution to a QString
    QLabel* position = new QLabel(positionString); //create label for position

    //create a horizontal layout from Position label and the positions of that writer
    QHBoxLayout* positionLayout = new QHBoxLayout;
    positionLayout->addWidget(positionLabel);
    positionLayout->addWidget(position);
    positionLayout->setAlignment(Qt::AlignLeft);

    QLabel* in1953Label = new QLabel("In 1953: ");
    QString aliveOrDeceasedString = QString::fromStdString(Writers.get_alive_or_dead(ID)); //get alive or dead data from Points class object Writers and convert to QString
    QLabel* aliveOrDeceased = new QLabel(aliveOrDeceasedString); //create alive or dead label

    //create a horizontal layout for in 1953 label and alive or deceased
    QHBoxLayout* aliveOrDeceasedLayout = new QHBoxLayout;
    aliveOrDeceasedLayout->addWidget(in1953Label);
    aliveOrDeceasedLayout->addWidget(aliveOrDeceased);
    aliveOrDeceasedLayout->setAlignment(Qt::AlignLeft);

    //Create a vertical layout for all the profile text information and add the labels
    QVBoxLayout* profile =  new QVBoxLayout;
    profile->addWidget(name);
    profile->addWidget(yearsOfLife);
    profile->addWidget(geographicLocation);
    profile->addLayout(institutionLayout);
    profile->addLayout(positionLayout);
    profile->addLayout(aliveOrDeceasedLayout);

    QWidget* profileWindow = new QWidget; //create widget for the profile window that is shown when a writer is clicked on

    //Create a label for the picture of the writer, each if statement adds the proper picture for each writer
    QLabel* profilePicture = new QLabel;

    //in each if statement, the profileWindow dimensions are set to fit the picture without causing it to be distorted
    if (ID == 1){
        QPixmap picture1(":/new/prefix1/sharov.jpeg");
        profilePicture->setPixmap(picture1);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(300);
        profileWindow->setFixedWidth(500);
    }
    else if (ID == 2){
        QPixmap picture2(":/new/prefix1/brushtein.jpg");
        profilePicture->setPixmap(picture2);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(300);
        profileWindow->setFixedWidth(500);
    }
    else if (ID == 3){
        QPixmap picture3(":/new/prefix1/panteleev.jpeg");
        profilePicture->setPixmap(picture3);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(250);
        profileWindow->setFixedWidth(400);
    }
    else if (ID == 4){
        QPixmap picture4(":/new/prefix1/alexin.png");
        profilePicture->setPixmap(picture4);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(250);
        profileWindow->setFixedWidth(500);
    }
    else if (ID == 5){
        QPixmap picture5(":/new/prefix1/sarnov.jpeg");
        profilePicture->setPixmap(picture5);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(250);
        profileWindow->setFixedWidth(400);

    }
    else if (ID == 6){
        QPixmap picture6(":/new/prefix1/zhitkov.jpg");
        profilePicture->setPixmap(picture6);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(400);
        profileWindow->setFixedWidth(850);
    }
    else if (ID == 8){
        QPixmap picture8(":/new/prefix1/vigdorova.jpg");
        profilePicture->setPixmap(picture8);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(350);
        profileWindow->setFixedWidth(650);

    }
    else if (ID == 9){
        QPixmap picture9(":/new/prefix1/belyh (left).jpg");
        profilePicture->setPixmap(picture9);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(250);
        profileWindow->setFixedWidth(400);
    }
    else if (ID == 10){
        QPixmap picture10(":/new/prefix1/dik.jpeg");
        profilePicture->setPixmap(picture10);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(300);
        profileWindow->setFixedWidth(650);

    }
    else if (ID == 11){
        QPixmap picture11(":/new/prefix1/paustovsky.jpg");
        profilePicture->setPixmap(picture11);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(350);
        profileWindow->setFixedWidth(650);

    }
    else if (ID == 12){
        QPixmap picture12(":/new/prefix1/chukovsky.jpg");
        profilePicture->setPixmap(picture12);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(350);
        profileWindow->setFixedWidth(650);
    }
    else if (ID == 13){
        QPixmap picture13(":/new/prefix1/panteleev.jpeg");
        profilePicture->setPixmap(picture13);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(400);
        profileWindow->setFixedWidth(800);
    }
    else if (ID == 14){
        QPixmap picture14(":/new/prefix1/lev_kassil.jpg");
        profilePicture->setPixmap(picture14);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(350);
        profileWindow->setFixedWidth(650);
    }
    else if (ID == 15){
        QPixmap picture15(":/new/prefix1/chukovskaya.jpg");
        profilePicture->setPixmap(picture15);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(350);
        profileWindow->setFixedWidth(750);
    }
    else if (ID == 16){
        QPixmap picture16(":/new/prefix1/kabo.jpg");
        profilePicture->setPixmap(picture16);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(250);
        profileWindow->setFixedWidth(500);
    }
    else if (ID == 17){
        QPixmap picture17(":/new/prefix1/prilezhaeva.jpg");
        profilePicture->setPixmap(picture17);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(350);
        profileWindow->setFixedWidth(600);
    }
    else if (ID == 18){
        QPixmap picture18(":/new/prefix1/bremener.jpg");
        profilePicture->setPixmap(picture18);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(250);
        profileWindow->setFixedWidth(500);
    }
    else if (ID == 19){
        QPixmap picture19(":/new/prefix1/gal.jpg");
        profilePicture->setPixmap(picture19);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(200);
        profileWindow->setFixedWidth(500);
    }
    else if (ID == 20){
        QPixmap picture20(":/new/prefix1/marshak.jpg");
        profilePicture->setPixmap(picture20);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(375);
        profileWindow->setFixedWidth(850);
    }
    else if (ID == 21){
        QPixmap picture21(":/new/prefix1/georgievskaya.jpg");
        profilePicture->setPixmap(picture21);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(300);
        profileWindow->setFixedWidth(500);
    }
    else if (ID == 22){
        QPixmap picture22(":/new/prefix1/gabbe.jpg");
        profilePicture->setPixmap(picture22);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(300);
        profileWindow->setFixedWidth(750);
    }
    else if (ID == 23){
        QPixmap picture23(":/new/prefix1/kataev.jpg");
        profilePicture->setPixmap(picture23);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(300);
        profileWindow->setFixedWidth(600);
    }
    else if (ID == 24){
        QPixmap picture24(":/new/prefix1/akim.jpg");
        profilePicture->setPixmap(picture24);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(300);
        profileWindow->setFixedWidth(550);
    }
    else if (ID == 26){
        QPixmap picture26(":/new/prefix1/trifonov.jpg");
        profilePicture->setPixmap(picture26);
        profilePicture->setScaledContents(true);
        profileWindow->setFixedHeight(225);
        profileWindow->setFixedWidth(500);
    }

    //Create horizontal layout to combine the text information and picture of the writer
    QHBoxLayout* fullProfile = new QHBoxLayout;
    fullProfile->addLayout(profile);
    //fullProfile->addSpacing(25);
    fullProfile->addWidget(profilePicture);
    fullProfile->setAlignment(Qt::AlignTop);


    profileWindow->setWindowTitle("Writer Profile");
    profileWindow->setLayout(fullProfile);
    profileWindow->show();

    //Repaint the mainwindow to only show the selected writer and their connections
    mode = ID + 17; //have to add 17 to the ID to get the proper mode number for the paintEvent function
    MainWindow::paintEvent(inputEvent);

}


//Create Actions Function
void MainWindow::createActions(){

    //Creates file menu
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    //Adding Select Writer option to the file menu
    select_writer = new QAction(tr("&Select Writer"), this);
    select_writer = fileMenu->addAction(tr("&Select Writer"), this, &MainWindow::createDockWindows);
    select_writer->setEnabled(true);

    fileMenu->addSeparator();


    //Create View Menu
    QMenu *viewMenu = menuBar()->addMenu(tr("&View"));

    //Adding All Connections options to view menu
    all_connections = new QAction(tr("&All Connections"), this);
    all_connections = viewMenu->addAction(tr("&All Connections"), this, &MainWindow::showAllConnections);
    all_connections->setEnabled(true);

    //Create Cirle Of Friends menu within View menu
    QMenu* circleOfFriendsMenu = viewMenu->addMenu("Circle of Friends");

    //Add Circle of Friends-Both Circles option to the Circle of Friends menu
    circle_of_friends_both = new QAction(tr("&Circle of Friends-Both Circles"), this);
    circle_of_friends_both = circleOfFriendsMenu->addAction(tr("&Circle of Friends-Both Circles"), this, &MainWindow::showBothCircles);
    circle_of_friends_both->setEnabled(true);

    //Add Circle of Friends-Women option to the Circle of Friends menu
    circle_of_friends_women = new QAction(tr("&Circle of Friends-Women"), this);
    circle_of_friends_women = circleOfFriendsMenu->addAction(tr("&Circle of Friends-Women"), this, &MainWindow::showWomenCircle);
    circle_of_friends_women->setEnabled(true);

    //Add Circle of Friends-Men option to the Circle of Friends menu
    circle_of_friends_men = new QAction(tr("&Circle of Friends-Men"), this);
    circle_of_friends_men = circleOfFriendsMenu->addAction(tr("&Circle of Friends-Men"), this, &MainWindow::showMenCircle);
    circle_of_friends_men->setEnabled(true);

    //Create Multiplicity menu within View menu
    QMenu* multiplicityMenu = viewMenu->addMenu("Multiplicity");

    //Add Acquaintance option to Multiplicity Menu
    multiplicity_acquaintance = new QAction(tr("&Acquaintance"), this);
    multiplicity_acquaintance = multiplicityMenu->addAction(tr("&Acquaintance"), this, &MainWindow::showAcquaintance);
    multiplicity_acquaintance->setEnabled(true);

    //Add Friendship 1 option to Multiplicity Menu
    multiplicity_friendship1 = new QAction(tr("&Friendship 1"), this);
    multiplicity_friendship1 = multiplicityMenu->addAction(tr("&Friendship 1"), this, &MainWindow::showFriendship1);
    multiplicity_friendship1->setEnabled(true);

    //Add Friendship 2 option to Multiplicity Menu
    multiplicity_friendship2 = new QAction(tr("&Friendship 2"), this);
    multiplicity_friendship2 = multiplicityMenu->addAction(tr("&Friendship 2"), this, &MainWindow::showFriendship2);
    multiplicity_friendship2->setEnabled(true);

    //Add Friendship 3 option to Multiplicity Menu
    multiplicity_friendship3 = new QAction(tr("&Friendship 3"), this);
    multiplicity_friendship3 = multiplicityMenu->addAction(tr("&Friendship 3"), this, &MainWindow::showFriendship3);
    multiplicity_friendship3->setEnabled(true);

    //Add Family option to Multiplicity Menu
    multiplicity_family = new QAction(tr("&Family"), this);
    multiplicity_family = multiplicityMenu->addAction(tr("&Family"), this, &MainWindow::showFamily);
    multiplicity_family->setEnabled(true);

    //Add Memorial option to Multiplicity Menu
    multiplicity_memorial = new QAction(tr("&Memorial"), this);
    multiplicity_memorial = multiplicityMenu->addAction(tr("&Memorial"), this, &MainWindow::showMemorial);
    multiplicity_memorial->setEnabled(true);

    //Add Assistance to Young Authors option to Multiplicity Menu
    multiplicity_assistance_to_the_young_authors = new QAction(tr("&Assistance to Young Authors"), this);
    multiplicity_assistance_to_the_young_authors = multiplicityMenu->addAction(tr("&Assistance to Young Authors"), this, &MainWindow::showAssistance);
    multiplicity_assistance_to_the_young_authors->setEnabled(true);

    //Add Professional 1 option to Multiplicity Menu
    multiplicity_professional1 = new QAction(tr("&Professional 1"), this);
    multiplicity_professional1 = multiplicityMenu->addAction(tr("&Professional 1"), this, &MainWindow::showProfessional1);
    multiplicity_professional1->setEnabled(true);

    //Add Professional 2 option to Multiplicity Menu
    multiplicity_professional2 = new QAction(tr("&Professional 2"), this);
    multiplicity_professional2 = multiplicityMenu->addAction(tr("&Professional 2"), this, &MainWindow::showProfessional2);
    multiplicity_professional2->setEnabled(true);

    //Add Master-Disciple option to Multiplicity Menu
    multiplicity_master_disciple = new QAction(tr("&Master-Disciple"), this);
    multiplicity_master_disciple = multiplicityMenu->addAction(tr("&Master-Disciple"), this, &MainWindow::showMasterDisciple);
    multiplicity_master_disciple->setEnabled(true);

    //Add Neighboring option to Multiplicity Menu
    multiplicity_neighboring = new QAction(tr("&Neighboring"), this);
    multiplicity_neighboring = multiplicityMenu->addAction(tr("&Neighboring"), this, &MainWindow::showProfessional1);
    multiplicity_neighboring->setEnabled(true);

    //Add Polemic option to Multiplicity Menu
    multiplicity_polemic = new QAction(tr("&Polemic"), this);
    multiplicity_polemic = multiplicityMenu->addAction(tr("&Polemic"), this, &MainWindow::showPolemic);
    multiplicity_polemic->setEnabled(true);

    //Add Common Involvement in Social Activism option to Multiplicity Menu
    multiplicity_common_involvement_in_social_activism = new QAction(tr("&Common Involvement in Social Activism"), this);
    multiplicity_common_involvement_in_social_activism = multiplicityMenu->addAction(tr("&Common Involvement in Social Activism"), this, &MainWindow::showCommonInvolvement);
    multiplicity_common_involvement_in_social_activism->setEnabled(true);

    //Create Strength Menu within View menu
    QMenu* strengthMenu = viewMenu->addMenu("Strength of Connection");

    //Add Strength 1 option to Strength menu
    strength_one = new QAction(tr("&Strength 1"), this);
    strength_one = strengthMenu->addAction(tr("&Strength 1"), this, &MainWindow::showStrength1);
    strength_one->setEnabled(true);

    //Add Strength 2 option to Strength menu
    strength_two = new QAction(tr("&Strength 2"), this);
    strength_two = strengthMenu->addAction(tr("&Strength 2"), this, &MainWindow::showStrength2);
    strength_two->setEnabled(true);

    //Add Strength 3 option to Strength menu
    strength_three = new QAction(tr("&Strength 3"), this);
    strength_three = strengthMenu->addAction(tr("&Strength 3"), this, &MainWindow::showStrength3);
    strength_three->setEnabled(true);

    //Add Strength 4 option to Strength menu
    strength_four = new QAction(tr("&Strength 4"), this);
    strength_four = strengthMenu->addAction(tr("&Strength 4"), this, &MainWindow::showStrength4);
    strength_four->setEnabled(true);

    //Add Strength 5 option to Strength menu
    strength_five = new QAction(tr("&Strength 5"), this);
    strength_five = strengthMenu->addAction(tr("&Strength 5"), this, &MainWindow::showStrength5);
    strength_five->setEnabled(true);

    viewMenu->addSeparator();
}

//Paint Event Function
void MainWindow::paintEvent(QPaintEvent* event) {
    QPainter  painter(this);

    // Strat Draw everything:

    // Give the position manually
    double Alexander_Raskin_x=60, Alexander_Raskin_y=450;
    double Alexander_Sharov_x=400, Alexander_Sharov_y=275;
    double Alexandra_Brushtein_x=150, Alexandra_Brushtein_y=200;
    double Alexey_Panteleev_x=50, Alexey_Panteleev_y=50;
    double Anatoly_Alexin_x=350, Anatoly_Alexin_y=65;
    double Benedict_Sarnov_x=1000, Benedict_Sarnov_y=100;
    double Boris_Zhitkov_x=700, Boris_Zhitkovx_y=550;
    double Evgeny_Shvartz_x=150, Evgeny_Shvartz_y=550;
    double Frida_Vigdorova_x=300, Frida_Vigdorova_y=150;
    double Georgy_Belyh_x=550, Georgy_Belyh_y=600;
    double Iosif_Dik_x=800, Iosif_Dik_y=150;
    double Konstantin_Paustovsky_x=1100, Konstantin_Paustovsky_y=300;
    double Korney_Chukovsky_x=900, Korney_Chukovsky_y=350;
    double Leonid_Panteleev_x=310, Leonid_Panteleev_y=510;
    double Lev_Kassil_x=600, Lev_Kassil_y=300;
    double Lidia_Chukovskaya_x=400, Lidia_Chukovskaya_y=400;
    double Lubov_Kabo_x=250, Lubov_Kabo_y=275;
    double Maria_Prilezhaeva_x=720, Maria_Prilezhaeva_y=425;
    double Max_Bremener_x=550, Max_Bremener_y=180;
    double Nora_Gal_x=100, Nora_Gal_y=300;
    double Samuil_Marshak_x=550, Samuil_Marshak_y=475;
    double Susanna_Georgievskaya_x=150, Susanna_Georgievskaya_y=350;
    double Tamara_Gabbe_x=200, Tamara_Gabbe_y=450;
    double Valentin_Kataev_x =900, Valentin_Kataev_y=500;
    double Yakov_Akim_x=600, Yakov_Akim_y=75;
    double Yuri_Sotnik_x=750, Yuri_Sotnik_y=50;
    double Yuri_Trifonov_x=975, Yuri_Trifonov_y=200;


    // Push back position
    x.push_back(Alexander_Raskin_x); y.push_back(Alexander_Raskin_y);
    x.push_back(Alexander_Sharov_x); y.push_back(Alexander_Sharov_y);
    x.push_back(Alexandra_Brushtein_x); y.push_back(Alexandra_Brushtein_y);
    x.push_back(Alexey_Panteleev_x); y.push_back(Alexey_Panteleev_y);
    x.push_back(Anatoly_Alexin_x); y.push_back(Anatoly_Alexin_y);
    x.push_back(Benedict_Sarnov_x); y.push_back(Benedict_Sarnov_y);
    x.push_back(Boris_Zhitkov_x); y.push_back(Boris_Zhitkovx_y);
    x.push_back(Evgeny_Shvartz_x); y.push_back(Evgeny_Shvartz_y);
    x.push_back(Frida_Vigdorova_x); y.push_back(Frida_Vigdorova_y);
    x.push_back(Georgy_Belyh_x); y.push_back(Georgy_Belyh_y);
    x.push_back(Iosif_Dik_x); y.push_back(Iosif_Dik_y);
    x.push_back(Konstantin_Paustovsky_x); y.push_back(Konstantin_Paustovsky_y);
    x.push_back(Korney_Chukovsky_x); y.push_back(Korney_Chukovsky_y);
    x.push_back(Leonid_Panteleev_x); y.push_back(Leonid_Panteleev_y);
    x.push_back(Lev_Kassil_x); y.push_back(Lev_Kassil_y);
    x.push_back(Lidia_Chukovskaya_x); y.push_back(Lidia_Chukovskaya_y);
    x.push_back(Lubov_Kabo_x); y.push_back(Lubov_Kabo_y);
    x.push_back(Maria_Prilezhaeva_x); y.push_back(Maria_Prilezhaeva_y);
    x.push_back(Max_Bremener_x); y.push_back(Max_Bremener_y);
    x.push_back(Nora_Gal_x); y.push_back(Nora_Gal_y);
    x.push_back(Samuil_Marshak_x); y.push_back(Samuil_Marshak_y);
    x.push_back(Susanna_Georgievskaya_x); y.push_back(Susanna_Georgievskaya_y);
    x.push_back(Tamara_Gabbe_x); y.push_back(Tamara_Gabbe_y);
    x.push_back(Valentin_Kataev_x); y.push_back(Valentin_Kataev_y);
    x.push_back(Yakov_Akim_x); y.push_back(Yakov_Akim_y);
    x.push_back(Yuri_Sotnik_x); y.push_back(Yuri_Sotnik_y);
    x.push_back(Yuri_Trifonov_x); y.push_back(Yuri_Trifonov_y);


    std::vector<int> v;
    std::vector<int> w;

    if(mode==0) { // Normal case to show all person
        v={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
        w={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
        for(size_t m=0; m<v.size(); ++m) {
            for(size_t n=m; n<w.size(); ++n) {
                int i=v[m];
                int j=w[n];
                if(Writers.get_strengths(i)[j]!=0) {
                    int s=Writers.get_strengths(i)[j];
                    painter.setPen(QPen(Qt::black, s));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==1) { // Circle of friend both
        v={5,8,10,15,18,19,21,22,24,26};
        w={5,8,10,15,18,19,21,22,24,26};
        for(size_t m=0; m<v.size(); ++m) {
            for(size_t n=m; n<w.size(); ++n) {
                int i=v[m];
                int j=w[n];
                if(Writers.get_strengths(i)[j]!=0) {
                    int s=Writers.get_strengths(i)[j];
                    painter.setPen(QPen(Qt::black, s));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==2) { // Circle of friend women
        v={8,15,19,21,22};
        w={8,15,19,21,22};
        for(size_t m=0; m<v.size(); ++m) {
            for(size_t n=m; n<w.size(); ++n) {
                int i=v[m];
                int j=w[n];
                if(Writers.get_strengths(i)[j]!=0) {
                    int s=Writers.get_strengths(i)[j];
                    painter.setPen(QPen(Qt::black, s));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==3) { // Circle of friend men
        v={5,10,18,24,16};
        w={5,10,18,24,16};
        for(size_t m=0; m<v.size(); ++m) {
            for(size_t n=m; n<w.size(); ++n) {
                int i=v[m];
                int j=w[n];
                if(Writers.get_strengths(i)[j]!=0) {
                    int s=Writers.get_strengths(i)[j];
                    painter.setPen(QPen(Qt::black, s));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==4) { // Acquaintances
        v.clear();
        w.clear();
        for(size_t i=0; i < Writers.get_size(); ++i) {
            for(size_t j=i; j<Writers.get_size(); ++j) {
                if(Writers.get_multiplicity(i)[j]=="Acquaintances" || Writers.get_multiplicity(i)[j]=="Acquaintances + Professional 1") {
                    v.push_back(i);
                    w.push_back(j);
                    painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==5) { // Friendship 1
        v.clear();
        w.clear();
        for(size_t i=0; i < Writers.get_size(); ++i) {
            for(size_t j=i; j<Writers.get_size(); ++j) {
                if(Writers.get_multiplicity(i)[j]=="Friendship 1" || Writers.get_multiplicity(i)[j]=="Friendship 1 + Professional 1" || Writers.get_multiplicity(i)[j]=="Friendship 1 + Professional 2 + Common involvement in social activism" || Writers.get_multiplicity(i)[j]=="Friendship 1 + Professional 2") {
                    v.push_back(i);
                    w.push_back(j);
                    painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==6) { // Friendship 2
        v.clear();
        w.clear();
        for(size_t i=0; i < Writers.get_size(); ++i) {
            for(size_t j=i; j<Writers.get_size(); ++j) {
                if(Writers.get_multiplicity(i)[j]=="Friendship 2" || Writers.get_multiplicity(i)[j]=="Friendship 2 + Professional 2") {
                    v.push_back(i);
                    w.push_back(j);
                    painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==7) { // Friendship 3
        v.clear();
        w.clear();
        for(size_t i=0; i < Writers.get_size(); ++i) {
            for(size_t j=i; j<Writers.get_size(); ++j) {
                if(Writers.get_multiplicity(i)[j]=="Friendship 3" || Writers.get_multiplicity(i)[j]=="Friendship 3 + Professional 1") {
                    v.push_back(i);
                    w.push_back(j);
                    painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==8) { // Family
        v.clear();
        w.clear();
        for(size_t i=0; i < Writers.get_size(); ++i) {
            for(size_t j=i; j<Writers.get_size(); ++j) {
                if(Writers.get_multiplicity(i)[j]=="Family" || Writers.get_multiplicity(i)[j]=="Family + Professional 2" || Writers.get_multiplicity(i)[j]=="Family + Common involvement in social activism") {
                    v.push_back(i);
                    w.push_back(j);
                    painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==9) { // Memorial
        v.clear();
        w.clear();
        for(size_t i=0; i < Writers.get_size(); ++i) {
            for(size_t j=i; j<Writers.get_size(); ++j) {
                if(Writers.get_multiplicity(i)[j]=="Memorial") {
                    v.push_back(i);
                    w.push_back(j);
                    painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==10) { // Assistance to young authors
        v.clear();
        w.clear();
        for(size_t i=0; i < Writers.get_size(); ++i) {
            for(size_t j=i; j<Writers.get_size(); ++j) {
                if(Writers.get_multiplicity(i)[j]=="Assistance to young authors" ) {
                    v.push_back(i);
                    w.push_back(j);
                    painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==11) { // Professional 1
        v.clear();
        w.clear();
        for(size_t i=0; i < Writers.get_size(); ++i) {
            for(size_t j=i; j<Writers.get_size(); ++j) {
                if(Writers.get_multiplicity(i)[j]=="Professional 1" || Writers.get_multiplicity(i)[j]=="Friendship 3 + Professional 1" || Writers.get_multiplicity(i)[j]=="Friendship 1 + Professional 1" || Writers.get_multiplicity(i)[j]=="Professional 1 + Neighboring" || Writers.get_multiplicity(i)[j]=="Professional 1 + Polemic") {
                    v.push_back(i);
                    w.push_back(j);
                    painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==12) { // Professional 2
        v.clear();
        w.clear();
        for(size_t i=0; i < Writers.get_size(); ++i) {
            for(size_t j=i; j<Writers.get_size(); ++j) {
                if(Writers.get_multiplicity(i)[j]=="Professional 2" || Writers.get_multiplicity(i)[j]=="Friendship 1 + Professional 2 + Common involvement in social activism" || Writers.get_multiplicity(i)[j]=="Assistance to young authors + Professional 2" || Writers.get_multiplicity(i)[j]=="Friendship 2 + Professional 2" || Writers.get_multiplicity(i)[j]=="Family + Professional 2" ||Writers.get_multiplicity(i)[j]=="Professional 2 + Master" ||Writers.get_multiplicity(i)[j]=="Professional 2 + Common involvement in social activism") {
                    v.push_back(i);
                    w.push_back(j);
                    painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==13) { // Master
        v.clear();
        w.clear();
        for(size_t i=0; i < Writers.get_size(); ++i) {
            for(size_t j=i; j<Writers.get_size(); ++j) {
                if(Writers.get_multiplicity(i)[j]=="Master" || Writers.get_multiplicity(i)[j]=="Professional 2 + Master") {
                    v.push_back(i);
                    w.push_back(j);
                    painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==14) { // Neighboring
        v.clear();
        w.clear();
        for(size_t i=0; i < Writers.get_size(); ++i) {
            for(size_t j=i; j<Writers.get_size(); ++j) {
                if(Writers.get_multiplicity(i)[j]=="Neighboring" || Writers.get_multiplicity(i)[j]=="Professional 1 + Neighboring") {
                    v.push_back(i);
                    w.push_back(j);
                    painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==15) { // Polemic
        v.clear();
        w.clear();
        for(size_t i=0; i < Writers.get_size(); ++i) {
            for(size_t j=i; j<Writers.get_size(); ++j) {
                if(Writers.get_multiplicity(i)[j]=="Polemic" || Writers.get_multiplicity(i)[j]=="Professional 1 + Polemic") {
                    v.push_back(i);
                    w.push_back(j);
                    painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==16) { // Common involvement in social activism
        v.clear();
        w.clear();
        for(size_t i=0; i < Writers.get_size(); ++i) {
            for(size_t j=i; j<Writers.get_size(); ++j) {
                if(Writers.get_multiplicity(i)[j]=="Common involvement in social activism" || Writers.get_multiplicity(i)[j]=="Friendship 1 + Professional 2 + Common involvement in social activism" || Writers.get_multiplicity(i)[j]=="Professional 2 + Common involvement in social activism" || Writers.get_multiplicity(i)[j]=="Family + Common involvement in social activism") {
                    v.push_back(i);
                    w.push_back(j);
                    painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    // mode 17 to 43 repersent the writers whose index from 0 to 26 in the Points class object Writers
    else if(mode==17) {
        v.clear();
        w.clear();
        int i=0;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0) {
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==18) {
        v.clear();
        w.clear();
        int i=1;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0) {
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==19) {
        v.clear();
        w.clear();
        int i=2;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0) {
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==20) {
        v.clear();
        w.clear();
        int i=3;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0) {
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==21) {
        v.clear();
        w.clear();
        int i=4;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0) {
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==22) {
        v.clear();
        w.clear();
        int i=5;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0) {
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==23) {
        v.clear();
        w.clear();
        int i=6;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==24) {
        v.clear();
        w.clear();
        int i=7;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==25) {
        v.clear();
        w.clear();
        int i=8;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==26) {
        v.clear();
        w.clear();
        int i=9;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==27) {
        v.clear();
        w.clear();
        int i=10;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==28) {
        v.clear();
        w.clear();
        int i=11;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==29) {
        v.clear();
        w.clear();
        int i=12;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==30) {
        v.clear();
        w.clear();
        int i=13;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==31) {
        v.clear();
        w.clear();
        int i=14;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==32) {
        v.clear();
        w.clear();
        int i=15;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==33) {
        v.clear();
        w.clear();
        int i=16;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==34) {
        v.clear();
        w.clear();
        int i=17;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==35) {
        v.clear();
        w.clear();
        int i=18;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==36) {
        v.clear();
        w.clear();
        int i=19;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==37) {
        v.clear();
        w.clear();
        int i=20;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==38) {
        v.clear();
        w.clear();
        int i=21;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==39) {
        v.clear();
        w.clear();
        int i=22;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==40) {
        v.clear();
        w.clear();
        int i=23;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==41) {
        v.clear();
        w.clear();
        int i=24;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==42) {
        v.clear();
        w.clear();
        int i=25;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==43) {
        v.clear();
        w.clear();
        int i=26;
        v={i};
        for(size_t j=0; j<Writers.get_size(); ++j) {
            if(Writers.get_strengths(i)[j]!=0){
                w.push_back(j);
                painter.setPen(QPen(Qt::black, Writers.get_strengths(i)[j]));
                painter.drawLine(x[i],y[i],x[j],y[j]);
            }
        }
    }
    else if(mode==44) { // Strengths = 1
        v.clear();
        w.clear();
        for(size_t i=0; i<Writers.get_size(); ++i) {
            for(size_t j=i; j<Writers.get_size(); ++j) {
                int s=Writers.get_strengths(i)[j];
                if(s==1) {
                    v.push_back(i);
                    w.push_back(j);
                    painter.setPen(QPen(Qt::black, s));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==45) { // Strengths = 2
        v.clear();
        w.clear();
        for(size_t i=0; i<Writers.get_size(); ++i) {
            for(size_t j=i; j<Writers.get_size(); ++j) {
                int s=Writers.get_strengths(i)[j];
                if(s==2) {
                    v.push_back(i);
                    w.push_back(j);
                    painter.setPen(QPen(Qt::black, s));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==46) { // Strengths = 3
        v.clear();
        w.clear();
        for(size_t i=0; i<Writers.get_size(); ++i) {
            for(size_t j=i; j<Writers.get_size(); ++j) {
                int s=Writers.get_strengths(i)[j];
                if(s==3) {
                    v.push_back(i);
                    w.push_back(j);
                    painter.setPen(QPen(Qt::black, s));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==47) { // Strengths = 4
        v.clear();
        w.clear();
        for(size_t i=0; i<Writers.get_size(); ++i) {
            for(size_t j=i; j<Writers.get_size(); ++j) {
                int s=Writers.get_strengths(i)[j];
                if(s==4) {
                    v.push_back(i);
                    w.push_back(j);
                    painter.setPen(QPen(Qt::black, s));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }
    else if(mode==48) { // Strengths = 5
        v.clear();
        w.clear();
        for(size_t i=0; i<Writers.get_size(); ++i) {
            for(size_t j=i; j<Writers.get_size(); ++j) {
                int s=Writers.get_strengths(i)[j];
                if(s==5) {
                    v.push_back(i);
                    w.push_back(j);
                    painter.setPen(QPen(Qt::black, s));
                    painter.drawLine(x[i],y[i],x[j],y[j]);
                }
            }
        }
    }


    // Draw the dots
    painter.setBrush(QBrush(Qt::lightGray));

    int thickness=8;
    int thickness_1=thickness+18;
    int thickness_2=thickness+30;

    for(size_t m=0; m<v.size(); ++m) {
        int i=v[m];
        // how big the dot is
        switch (Writers.get_institution_number(i)) {
        case 0 :
            painter.setPen(QPen(Qt::black, thickness-7));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            break;
        case 1 :
            painter.setPen(QPen(Qt::red, thickness));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));

            break;
        case 2 :
            painter.setPen(QPen(Qt::blue, thickness));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));

            break;
        case 3 :
            painter.setPen(QPen(Qt::cyan, thickness));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));

            break;
        case 4 :
            painter.setPen(QPen(Qt::red, thickness_1));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            painter.setPen(QPen(Qt::blue, thickness));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));

            break;
        case 5 :
            painter.setPen(QPen(Qt::darkGreen, thickness_2));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            painter.setPen(QPen(Qt::red, thickness_1));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            painter.setPen(QPen(Qt::blue, thickness));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            break;
        case 6 :
            painter.setPen(QPen(Qt::darkGreen, thickness_1));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            painter.setPen(QPen(Qt::blue, thickness));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            break;
        case 7 :
            painter.setPen(QPen(Qt::cyan, thickness_2));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            painter.setPen(QPen(Qt::darkGreen, thickness_1));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            painter.setPen(QPen(Qt::blue, thickness));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            break;
        case 8 :
            painter.setPen(QPen(Qt::cyan, thickness_1));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            painter.setPen(QPen(Qt::blue, thickness));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            break;
        default:
            break;
        }
    }
    for(size_t m=0; m<w.size(); ++m) {
        int i=w[m];
        // how big the dot is
        switch (Writers.get_institution_number(i)) {
        case 0 :
            painter.setPen(QPen(Qt::black, thickness-7));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            break;
        case 1 :
            painter.setPen(QPen(Qt::red, thickness));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));

            break;
        case 2 :
            painter.setPen(QPen(Qt::blue, thickness));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));

            break;
        case 3 :
            painter.setPen(QPen(Qt::cyan, thickness));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));

            break;
        case 4 :
            painter.setPen(QPen(Qt::red, thickness_1));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            painter.setPen(QPen(Qt::blue, thickness));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));

            break;
        case 5 :
            painter.setPen(QPen(Qt::darkGreen, thickness_2));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            painter.setPen(QPen(Qt::red, thickness_1));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            painter.setPen(QPen(Qt::blue, thickness));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            break;
        case 6 :
            painter.setPen(QPen(Qt::darkGreen, thickness_1));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            painter.setPen(QPen(Qt::blue, thickness));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            break;
        case 7 :
            painter.setPen(QPen(Qt::cyan, thickness_2));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            painter.setPen(QPen(Qt::darkGreen, thickness_1));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            painter.setPen(QPen(Qt::blue, thickness));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            break;
        case 8 :
            painter.setPen(QPen(Qt::cyan, thickness_1));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            painter.setPen(QPen(Qt::blue, thickness));
            painter.drawEllipse(QPointF(x[i],y[i]), width + 2*Writers.number_of_connections(i), height+ 2*Writers.number_of_connections(i));
            break;
        default:
            break;
        }
    }


    // Set up the font for the title
    QFont font("Times", 8, QFont::Bold);
    font.setItalic(true);
    painter.setFont(font);
    QPen pen(Qt::black);
    painter.setPen(pen);


    // Draw the names
    for(size_t m=0; m<v.size(); ++m) {
        int i=v[m];
        QString qstr = QString::fromStdString(Writers.get_last_name(i));
        painter.drawText(x[i]-28, y[i]+5, qstr);
    }

    for(size_t m=0; m<w.size(); ++m) {
        int i=w[m];
        QString qstr = QString::fromStdString(Writers.get_last_name(i));
        painter.drawText(x[i]-28, y[i]+5, qstr);
    }


    // Draw Legend
    for(size_t i=0; i<5; ++i) {
        QString qstr;
        switch (i) {
        case 0 :
            qstr = QString::fromStdString("None Institution");
            painter.setPen(QPen(Qt::black));
            painter.drawText(1000, 520, qstr);
            break;
        case 1 :
            qstr = QString::fromStdString("Leningrad Branch of Detgiz Publishing House");
            painter.setPen(QPen(Qt::red));
            painter.drawText(1000, 535, qstr);
            break;
        case 2 :
            qstr = QString::fromStdString("Moscow Children's Section");
            painter.setPen(QPen(Qt::blue));
            painter.drawText(1000, 550, qstr);
            break;
        case 3 :
            qstr = QString::fromStdString("Gorky Literary Institute");
            painter.setPen(QPen(Qt::cyan));
            painter.drawText(1000, 565, qstr);
            break;
        case 4 :
            qstr = QString::fromStdString("\"Youth\" Journal");
            painter.setPen(QPen(Qt::darkGreen));
            painter.drawText(1000, 580, qstr);
            break;
        default:
            break;
        }
    }
}

//Virtual Descructor for MainWindow
MainWindow::~MainWindow()
{
    delete ui;
}
