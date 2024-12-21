import {default as Roster} from "./roster" 
import {Degree} from "./degree"


const studentData: Array<string> = [ 
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,jake,fromstatefarm,jakefrom@statefarm.com,17,25,35,42,SOFTWARE"
]

const roster = new Roster()

for(let i = 0; i < studentData.length; i++) {
    roster.parseString(studentData[i])
}


console.log("Display all students:")

roster.printAllStudents();

 

console.log("Display invalid emails:")
roster.printInvalidEmails();
 

for (let i = 0; i < 5; i++) {
    roster.printAverageDaysInCourse(roster.studentRoster[i].getID());
}
 

console.log("Showing students from degree program: SOFTWARE")

roster.printByDegreeProgram(Degree.SOFTWARE);

 

console.log("Removing A3")
roster.removeStudent("A3");
roster.printAllStudents();
 

console.log("Removing A3 again")
roster.removeStudent("A3");

console.log("Program finished")