/*Instructions
To Start:
Click the green triangle Run button on the lower left hand side of the screen

To Access Functionality of the Program:
Main Screen shows all writers and their connections
      Larger circles indicate the writer has more connections
      The colored circles surrounding the writers correspond to the institution(s) the writer belongs to (see the legend in the bottom right)

File Menu
      Select Writer Option
          Clicking this opens a dock window on the left side of the screen with the writers' names
          Clicking on a writer's name:
              A separate window opens showing their information and a photo
              The main screen is changed to only show that writer and their connections

View Menu
      All Connections Option
          Clicking this returns the main window to its original setting showing all the writers
      Circle of Friends Option
          Choose from three options to have only writers in that circle show on the screen
              Circle of Writers - Both Circles
              Circle of Writers - Women
              Circle of Writers - Men
      Multiplicity Option
          Choose from 13 options to have only writers with that multiplicity show on the screen
              Acquaintance (not very close relationships determined by the friendship or deep professional relationships of one’s friend to the person in question)
              Friendship 1 (ties based on social, generational, professional and, speaking widely, symbolical equality or on the great dependence of the “higher-ranking” person from the “lower-ranking”)
              Friendship 2 (friendly relations with a moral and/or aesthetical authority)
              Friendship 3 (current not very deep relationships determined by intensive friendship or collaboration in the past)
              Family
              Memorial (friendly and deep relationships in the past with a person already dead, but still important and influential for the certain actor)
              Assistance to Young Authors
              Professional 1 (institutionalized surface professional relationships, determined by the fact of belonging to the same corporation, work in and for the same institutions, vacations spent at the same Writer’s Union sanatoriums, etc.)
              Professional 2 (deep professional relationships which imply involvement of one actor in the process of creation or editing of the text written by  another actor, including assistance with communications with the publishing houses and journal editorials, writing positive peer-reviews and publishing positive reviews, organizational support and investing one’s moral and professional authority to the projects of the person in question, common editorial work on the same book collections or special issues of journals, etc.)
              Master-Disciple
              Neighboring
              Polemic
              Common Involvement in Social Activism
      Strength Option
          Choose from 5 strength options to only have writers with that strength of connection show on the screen
              Strength 1 (weakest connection)
              Strength 2
              Strength 3
              Strength 4
              Strength 5 (strongest connection)



To Interpret the Data File:
DATA ORGANIZATION
(random variable) (FirstName_LastName) (Institution Number) (Years of Life) (Position in Institution) (Georgraphic Location) (Cirlce of Friends) (AliveOrDead) (Strengths) (Multiplicity)

RANDOM VARIABLE
- can be any letter and used for proper integration

NAME
- must have _ between first and last name

INSTITUTION NUMBER
- 0 = none
- 1 = Leningrad Branch of Detgiz Publishig House
- 2 = Moscow Children's Section
- 3 = Gorky Literary Institute
- 4 = Leningrad Branch of Detgiz Publishig House, Moscow Children's Section
- 5 = Leningrad Branch of Detgiz Publishig House, Moscow Children's Section, Youth Journal
- 6 = Moscow Children's Section, Youth Journal
- 7 = Gorky Literary Institute, Moscow Children's Section, Youth Journal
- 8 = Gorky Literary Institute, Moscow Children's Section

YEARS OF LIFE
- (Born-Died)

POSITION IN INSTITUTION
- None = none
- 1a = Gorky Literary Institute Professor
- 3f = Leningrad Branch of Detgiz Publishing House Author
- 2d = Youth Journal Influential Figure
- 1a2d4e = Gorky Literary Institute Professor, Moscow Children's Section Editor, Youth Journal Influential Figure
- 3e = Leningrad Branch of Detgiz Publishing House Editor
- 2c = Youth Journal Editorial Board
- 2c3b = Leningrad Branch of Detgiz Publishing House Editor-in-Chief, Youth Journal Editorial Board
- 2b = Youth Journal Editor-in-Chief

GEOGRAPHIC LOCATION
- Location of writer

CIRCLE OF FRIENDS
- Young_Men_Writers
- Mature_Men_Writers
- Young-Women_Writers
- Mature_Women_Writers
- None = no circle of friends

ALIVE OR DEAD
- Alive during time period or had died previously

STRENGTHS
- must put consecutively (without spaces) to properly work with data
- Each value corresponds to the connection that a person has with a another member
- e.g. 020000005000200310030000000
- 0 = no connection
- 1 = weakest connection
- 2 = weak connection
- 3 = average connection
- 4 = strong connection
- 5 = strongest connection

MULTIPLICITY
- Similar to strengths in the fact that must be input conesecutively without spaces
- Each value corresponds to the type of connection that a person has with a another member (e.g. Friend, family, acquantance, etc)
- #b######u###c##ba##b#######
- a = "Acquaintances"
- b = "Friendship 1"
- c = "Friendship 2"
- d = "Friendship 3"
- e = "Family"
- f = "Memorial"
- g = "Assistance to young authors"
- h = "Professional 1"
- i = "Professional 2"
- j = "Master"
- k = "Neighboring"
- l = "Polemic"
- m = "Common involvement in social activism"
- n = "Friendship 3 + Professional 1"
- o = "Acquaintances + Professional 1"
- p = "Friendship 1 + Professional 1"
- q = "Friendship 1 + Professional 2 + Common involvement in social activism"
- r = "Friendship 1 + Professional 2"
- s = "Assistance to young authors + Professional 2"
- t = "Friendship 2 + Professional 2"
- u = "Family + Professional 2"
- v = "Professional 2 + Master"
- w = "Professional 1 + Neighboring"
- x = "Professional 1 + Polemic"
- y = "Professional 2 + Common involvement in social activism"
- z = "Family + Common involvement in social activism"
- # = "None"

*/
