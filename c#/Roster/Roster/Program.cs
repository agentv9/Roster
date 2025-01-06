using System;

namespace Roster
{
    internal class Program
    {
        static void Main()
        {
            string[] studentData = {
                "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                "A5,jake,fromstatefarm,jakefrom@statefarm.com,17,25,35,42,SOFTWARE"
            };

            Roster roster = new Roster();

            foreach (string student in studentData)
            {
                roster.parseString(student);
            }

            Console.WriteLine("\nDisplay all students:");
            roster.printAllStudents();


            Console.WriteLine("\nDisplay invalid emails:");
            roster.printInvalidEmails();

            Console.WriteLine("\n");
            for (int i = 0; i < roster.StudentRoster.Length; i++)
            {
                roster.printAverageDaysInCourse(roster.StudentRoster[i].getID());
            }

            Console.WriteLine("\nShowing students from degree program: SOFTWARE");
            roster.printByDegreeProgram(Degree.SOFTWARE);


            Console.WriteLine("\nRemoving A3");
            roster.removeStudent("A3");
            roster.printAllStudents();



            Console.WriteLine("\nRemoving A3 again");
            roster.removeStudent("A3");
            Console.WriteLine("\nProgram finished");

        }
    }
}