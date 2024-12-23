<?php
require(__DIR__ ."/Student.php");

class Roster {
    public array $studentRoster = [];

    function parseString(string $data) {
        $array = explode(",", $data);
        $degree = null;

        if($array[8] == "SECURITY"){
            $degree = Degree::SECURITY;
        }elseif($array[8] == "NETWORK"){
            $degree = Degree::NETWORK;
        }else {
            $degree = Degree::SOFTWARE;
        }
       
        $this->addStudent($array[0], $array[1], $array[2], $array[3], $array[4], [$array[5], $array[6], $array[7]], $degree);
    }

    function addStudent(string $id, string $firstName, string $lastName, string $emailAddress, int  $age, array $coursedays, Degree $degreeprogram) {
    $student = new Student($id, $firstName, $lastName,  $emailAddress,   $age,  $degreeprogram, $coursedays);
    array_push($this->studentRoster, $student);
    }
    function removeStudent(string $id) {
        $located = false;
        for ($x = 0; $x < sizeof($this->studentRoster); $x++) {
            if ($this->studentRoster[$x]->getID() == $id) {
                array_splice($this->studentRoster, $x, 1);
                $located = true;
            }
          }
        
        if($located == false) {
            print("The student with the ID: " . $id . " was not found.");
        }
    }
    function printAllStudents() {
        foreach ($this->studentRoster as $student){
            $student->Print();
        }
    }
    function printAverageDaysInCourse(string $id) {
        $totalDays = 0;

        foreach ($this->studentRoster as $student){
           if($student->getID() == $id){
            foreach ($student->getCourseDays() as $day) {
                $totalDays += $day;
            }
           }   
          }
          $averageDays = $totalDays / 3;
          print("Student ID: " . $id . ", Average days in course is: " . $averageDays."\n");
    }
    function printInvalidEmails() {
        foreach ($this->studentRoster as $student){
          $email = $student->getEmail();
          if(str_contains($email, " ") || !str_contains($email, ".")|| !str_contains($email, "@")) {
            print($email . " - is invalid.\n");
          }
            
        }
    }
    function printByDegreeProgram(Degree $degree) {
        foreach ($this->studentRoster as $student){
            if($student->getDegree()  == $degree) {
                $student->Print();
            }
        }
    }
}