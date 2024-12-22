from roster import Roster
from degree import Degree
studentData = [ 
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,jake,fromstatefarm,jakefrom@statefarm.com,17,25,35,42,SOFTWARE"
]


roster = Roster()

for data in studentData:
    roster.parseString(data)

print("\nDisplay all students:")

roster.printAllStudents();

 

print("\nDisplay invalid emails:")
roster.printInvalidEmails();
 
print("\n")
for student in roster.studentRoster:
    roster.printAverageDaysInCourse(student.getID());

 

print("\nShowing students from degree program: SOFTWARE")

roster.printByDegreeProgram(Degree.SOFTWARE);

 

print("\nRemoving A3")
roster.removeStudent("A3");
roster.printAllStudents();
 

print("\nRemoving A3 again")
roster.removeStudent("A3");

print("\nProgram finished")