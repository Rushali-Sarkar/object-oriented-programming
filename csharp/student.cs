using System;
using System.Collections.Generic;

namespace StudentDetails {

    class Program {


        static void DisplayDetails(List<Student> students) {

            foreach (Student nthstudent in students)
                nthstudent.Display();

            return;
        }

        static void Main(string[] args) {

            var students = new List<Student>();
            bool adding = true;

            while (adding) {

                var nthstudent = new Student();

                Console.WriteLine("Enter the name of the student.");
                nthstudent.Name = Console.ReadLine();

                Console.WriteLine("Enter {0}'s Roll Number.", nthstudent.Name);
                nthstudent.RollNumber = int.Parse(Console.ReadLine());

                Console.WriteLine("Enter {0}'s Phone Number.", nthstudent.Name);
                nthstudent.Phone = int.Parse(Console.ReadLine());

                Console.WriteLine("Enter {0}'s Maths Grade.", nthstudent.Name);
                nthstudent.MathsGrade = double.Parse(Console.ReadLine());

                Console.WriteLine("Enter {0}'s Physics Grade.", nthstudent.Name);
                nthstudent.PhysicsGrade = double.Parse(Console.ReadLine());

                Console.WriteLine("Enter {0}'s Chemistry Grade.", nthstudent.Name);
                nthstudent.ChemistryGrade = double.Parse(Console.ReadLine());

                Console.WriteLine("Enter {0}'s Computer Grade.", nthstudent.Name);
                nthstudent.ComputerGrade = double.Parse(Console.ReadLine());

                students.Add(nthstudent);
                Student.Count++;

                Console.WriteLine("Do you want to Add more students to the list ? (y / n)");
                var choice = Console.ReadLine();

                if (choice != "y")
                    adding = false;
            }

            Console.WriteLine("The number of students added: {0}", Student.Count);
            DisplayDetails(students);
            return;
        }
    }
}

class Student {

    
    static public int Count = 0;
    
    public string Name;
    public int RollNumber;
    public double MathsGrade;
    public double PhysicsGrade;
    public double ChemistryGrade;
    public double ComputerGrade;
    private int phone;

    public int Phone {

        set {
            phone = value;
        }
    }

    public void Display() {

        Console.WriteLine("Name            : {0}", Name);
        Console.WriteLine("Roll Number     : {0}", RollNumber);
        Console.WriteLine("Phone Number    : {0}", phone);
        Console.WriteLine("Maths Grades    : {0}", MathsGrade);
        Console.WriteLine("Physics Grades  : {0}", PhysicsGrade);
        Console.WriteLine("Chemistry Grades: {0}", ChemistryGrade);
        Console.WriteLine("Computer Grades : {0}", ComputerGrade);
        
        return;
    }
}
