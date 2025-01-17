package com.kaseknife95;

public class Main {
    public static void main(String[] args) {
      String[] studentData = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,jake,fromstatefarm,jakefrom@statefarm.com,17,25,35,42,SOFTWARE"    
      };

      Roster roster = new Roster();

      
for(int i = 0; i < studentData.length; i++) {
    roster.parseString(studentData[i]);
}


System.out.println("\nDisplay all students:");

roster.printAllStudents();

 

System.out.println("\nDisplay invalid emails:");
roster.printInvalidEmails();
 
System.out.println("\n");
for (int i = 0; i < 5; i++) {
    roster.printAverageDaysInCourse(roster.studentRoster[i].getID());
}
 

System.out.println("\nShowing students from degree program: SOFTWARE");

roster.printByDegreeProgram(Degree.SOFTWARE);

 

System.out.println("\nRemoving A3");
roster.removeStudent("A3");
roster.printAllStudents();
 

System.out.println("\nRemoving A3 again");
roster.removeStudent("A3");

System.out.println("\nProgram finished");
    }
}