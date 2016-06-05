#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "main.h"
#include <QMainWindow>
#include <QListWidgetItem>
#include "Writer.h"
#include "Points.h"

/* MainWindow class
@brief Contains the functions needed to draw the connections, and create the menus and actions to allow interaction with the data
*/
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

    void createActions();
    void createWriterProfile(int ID);

    void paintEvent(QPaintEvent* event);


public slots:

    void listItemClicked(QListWidgetItem * item);
    void createDockWindows();

    void showAllConnections();

    void showBothCircles();
    void showMenCircle();
    void showWomenCircle();

    void showAcquaintance();
    void showFriendship1();
    void showFriendship2();
    void showFriendship3();
    void showFamily();
    void showMemorial();
    void showAssistance();
    void showProfessional1();
    void showProfessional2();
    void showMasterDisciple();
    void showNeighboring();
    void showPolemic();
    void showCommonInvolvement();

    void showStrength1();
    void showStrength2();
    void showStrength3();
    void showStrength4();
    void showStrength5();


private:
    Points Writers;
    Ui::MainWindow *ui;


    QListWidget* writerList;

    QAction* add_writer;
    QAction* select_writer;

    QAction* all_connections;

    QAction* circle_of_friends_both;
    QAction* circle_of_friends_men;
    QAction* circle_of_friends_women;

    QAction* multiplicity_acquaintance;
    QAction* multiplicity_friendship1;
    QAction* multiplicity_friendship2;
    QAction* multiplicity_friendship3;
    QAction* multiplicity_family;
    QAction* multiplicity_memorial;
    QAction* multiplicity_assistance_to_the_young_authors;
    QAction* multiplicity_professional1;
    QAction* multiplicity_professional2;
    QAction* multiplicity_master_disciple;
    QAction* multiplicity_neighboring;
    QAction* multiplicity_polemic;
    QAction* multiplicity_common_involvement_in_social_activism;

    QAction* strength_one;
    QAction* strength_two;
    QAction* strength_three;
    QAction* strength_four;
    QAction* strength_five;


    std::vector<double> x;
    std::vector<double> y;
    const double width = 40.0, height = 10.0;

    int mode=0; //used to set the paint event mode
    QPaintEvent* inputEvent;


};

#endif

