using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace Roster
{
    class Student
    {
        string id;
        string First_Name;
        string Last_Name;
        string Email;
        int Age;
        Degree Student_Degree;
        int[] CourseDays;

        public Student(string id, string firstname, string lastname, string email, int age, Degree degree, int[] days)
        {
            this.setID(id);
            this.setFirstName(firstname);
            this.setLastName(lastname);
            this.setEmail(email);
            this.setAge(age);
            this.setDegree(degree);
            this.setCourseDays(days);
        }
        
        public string getID(){return id;}
        public string getFirstName() {return this.First_Name;}
        public string getLastName() { return this.Last_Name; }
        public string getEmail() { return this.Email; }
        public int getAge() { return this.Age; }
        public Degree getDegree() { return this.Student_Degree; }
        public int[] getCourseDays() { return this.CourseDays; }

        public void setID(string id) { this.id = id; }
        public void setFirstName(string name) {this.First_Name = name;}
        public void setLastName(string name) {this.Last_Name = name; }
        public void setEmail(string email) {this.Email = email; }
        public void setAge(int age) {this.Age = age; }
        public void setDegree(Degree degree) {this.Student_Degree = degree; }
        public void setCourseDays(int[] days) {this.CourseDays = days; }

        public void Print() {Console.WriteLine(this.getID() + "   " + this.getFirstName() + "   " + this.getLastName() + "   " + this.getEmail() + "   " + this.getAge() + "   " + this.getDegree() + "   " + string.Join(" ", getCourseDays()) ); }
    }
}
