package com.kaseknife95;

public class Roster {
    public Student[] studentRoster = {};
    public void parseString(String data) {
        String[] array = data.split(",");
        Degree degree;

        if(array[8] == "SECURITY"){
            degree = Degree.NETWORK;
        }else if(array[8] == "NETWORK"){
            degree = Degree.NETWORK;
        }else {
            degree = Degree.SOFTWARE;
        }

        int[] days = {Integer.parseInt(array[5]), Integer.parseInt(array[6]), Integer.parseInt(array[7])};

        this.addStudent(array[0], array[1], array[2], array[3], Integer.parseInt(array[4]),degree, days );
        return;
    }
    public void addStudent(String id, String First_Name, String Last_Name, String Email, int Age, Degree Student_Degree, int[] CourseDays) {
        Student student = new Student( id,  First_Name,  Last_Name,  Email,  Age,  Student_Degree,  CourseDays);
        this.studentRoster = ArrayHelper.push(studentRoster, student);
        return;
    }
    public void removeStudent(String id) {
        boolean located = false;
        for (int i = 0; i < this.studentRoster.length; i++){
            if(this.studentRoster[i].getID().equals(id)) {
                located = true;
              this.studentRoster = ArrayHelper.removeElement(this.studentRoster, i);
               
            }
        }
        if (located == false) {
           System.out.println("The student with the ID: " + id + " was not found.");
        }
        return;
    }
    public void printAllStudents() {
        for(int i = 0; i < this.studentRoster.length; i++) {
           this.studentRoster[i].Print();
        } 
        return;
    }
    public void printAverageDaysInCourse(String id) {
        int totalDays = 0;

        for(int i = 0; i < this.studentRoster.length; i++) {
            if(this.studentRoster[i].getID() == id){
                for(int day : this.studentRoster[i].getCourseDays()){
                    totalDays += day;
                }
            }
        }

        int averageDays = totalDays / 3;

        System.out.println("Student ID: " + id + ", Average days in course is: " + averageDays);
        return;
    }
    public void printInvalidEmails() {
        for(int i = 0; i < this.studentRoster.length; i++) {
            String email = this.studentRoster[i].getEmail();
 
            if(email.contains(" ") || !email.contains("@") || !email.contains(".")) {
             System.out.println(email + " - Is invalid.");
            }
 
         }
         return;
    }
    public void printByDegreeProgram(Degree degree) {
        for(int i = 0; i < this.studentRoster.length; i++) {
            if(this.studentRoster[i].getDegree() == degree){
               this.studentRoster[i].Print();
            }
        }
        return;
    }
}
