/*Documentation

Writer Class
@brief Creates Writer objects with corresponding information

@brief Get Name Function
@return Corresponding name for specific Writer object

@brief Get Institution Number Function
@return Corresponding institution number for specific Writer object

@brief Get Years of Life Function
@return Corresponding years of life for specific Writer object

@brief Get Position in Institution Function
@return Corresponding position in institution for specific Writer object

@brief Get Geographic Location Function
@return Corresponding geographic location for specific Writer object

@brief Get Circle of Friends Function
@return Corresponding circle of friends for specific Writer object

@brief Get Alive or Dead Function
@return Corresponding alive or dead for specific Writer object

@brief Get Strengths Function
@return std::vector<int> that corresponds to strengths for a specific Writer object

@brief Get Multiplicity Function
@return std::vector<std::string> that corresponds to multiplicity for a specific Writer object


Points Class
@brief Stores Writer pointer objects in std::vector<Writer*> to properly manage allocated memory using Resource Aquisition in Initialization.

@brief Virtual Destructor
@detail Properly deallocates memory using RAII

@brief Push_Back Function
@param pt New Writer object that is being added to std::vector<Writer*> points

@brief Get Size of std::vector<Writer*> Function
@return Total number of Writers objects in Points vector

@brief Get Number of Connections Function
@param id Index of corresponding Writer
@return The number of connections that corresponds to a specific Writer

@brief Find ID For Corresponding Name Function
@param s Name of Writer we are searching for
@return Function to find name and return corresponding ID

@brief Converts Institution Number to String Function
@param number Interger value corresponding to specific institution
@return Name of corresponding institution

@brief Print Names Function

@brief Print Institution Numbers Function

@brief Get First Name Function
@param id Index of corresponding Writer
@return First name that corresponds to a specific Writer

@brief Get Last Name Function
@param id Index of corresponding Writer
@return Last name that corresponds to a specific Writer

@brief Get Name Function
@param id Index of corresponding Writer
@return Corresponding name for specific Writer object

@brief Get Institution Number Function
@param id Index of corresponding Writer
@return Corresponding institution number for specific Writer object

@brief Get Years of Life Function
@param id Index of corresponding Writer
@return Corresponding years of life for specific Writer object

@brief Get Position in Institution Function
@param id Index of corresponding Writer
@return Corresponding position in institution for specific Writer object

@brief Get Geographic Location Function
@param id Index of corresponding Writer
@return Corresponding geographic location for specific Writer object

@brief Get Circle of Friends Function
@param id Index of corresponding Writer
@return Corresponding circle of friends for specific Writer object

@brief Get Alive or Dead Function
@param id Index of corresponding Writer
@return Corresponding alive or dead for specific Writer object

@brief Get Strength Function
@param id Index of corresponding Writer
@return std::vector<int> that corresponds to strengths for a specific Writer object

@brief Get Multiplicity Function
@param id Index of corresponding Writer
@return std::vector<std::string> that corresponds to multiplicity for a specific Writer object


MainWindow
@brief Contains the functions needed to draw the connections, and create the menus and actions to allow interaction with the data

@brief MainWindow Constructor
@detail Reads in data stored in Data1.txt to create Writer objects and stores those objects in a Points class object, Writers

@brief List Item Clicked Function
@detail calls find function which will take in a string item and return an int for the ID
        then uses that ID to call the createWriterProfile when a writer is selected from the dock widget

@brief Create Dock Windows Function
@detail Creates dock widget containing names of each writer and sets up signal/slot with listItemClicked function

@brief Show All Connections Function
@details calls Paint Event function to repaint mainwindow to show all connections

@brief Show Both Circles Function
@details calls Paint Event function to repaint mainwindow to show both circles of friends

@brief Show Women Circle Function
@details calls Paint Event function to repaint mainwindow to show women circle of friends

@brief Show Men Circle Function
@details calls Paint Event function to repaint mainwindow to show men circle of friends

@brief Show Acquaintance Function
@details calls Paint Event function to repaint mainwindow to show acquaintance connections

@brief Show Friendship 1 Function
@details calls Paint Event function to repaint mainwindow to show friendship 1 connections

@brief Show Friendship 2 Function
@details calls Paint Event function to repaint mainwindow to show friendship 2 connections

@brief Show Friendship 3 Function
@details calls Paint Event function to repaint mainwindow to show friendship 3 connections

@brief Show Family Function
@details calls Paint Event function to repaint mainwindow to show family connections

@brief Show Memorial Function
@details calls Paint Event function to repaint mainwindow to show memorial connections

@brief Show Assistance Function
@details calls Paint Event function to repaint mainwindow to show assistance connections

@brief Show Professional 1 Function
@details calls Paint Event function to repaint mainwindow to show professional 1 connections

@brief Show Professional 2 Function
@details calls Paint Event function to repaint mainwindow to show professional 2 connections

@brief Show Master-Disciple Function
@details calls Paint Event function to repaint mainwindow to show master-disciple connections

@brief Show Neighboring Function
@details calls Paint Event function to repaint mainwindow to show neighboring connections

@brief Show Polemic Function
@details calls Paint Event function to repaint mainwindow to show polemic connections

@brief Show Common Involvement Function
@details calls Paint Event function to repaint mainwindow to show common involvement connections

@brief Show Strength 1 Function
@details calls Paint Event function to repaint mainwindow to show strength 1 connections

@brief Show Strength 2 Function
@details calls Paint Event function to repaint mainwindow to show strength 2 connections

@brief Show Strength 3 Function
@details calls Paint Event function to repaint mainwindow to show strength 3 connections

@brief Show Strength 4 Function
@details calls Paint Event function to repaint mainwindow to show strength 4 connections

@brief Show Strength 5 Function
@details calls Paint Event function to repaint mainwindow to show strength 5 connections

@brief Create Writer Profile function
@detail this function is called when a writer's name is selected from the dock widget of the Select Writer option
        The profile window shows the writer's information and a picture if one was provided
@param ID is an int representing a Writer object in the Points class object Writers based on its index

@brief Create Actions Function
@detail Creates two main menus File and View and then options within those menus

@brief Paint Event Function
@detail paints the main graphic interface
@param event is unused but needed for compiling

@brief Virtual Destructor for MainWindow
@detail Properly deallocates memory using RAII

*/
