using namespace std;

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Student
{
	private:
	    const char* m_studentName;
		const char* m_studentClass;
		uint m_studentPhysicsGrades;

		const uint m_minGrade = 0;
		const uint m_maxGrade = 100;
		
		friend class Teacher;
        
        void setGrade(unsigned int newGrade)
        {
            m_studentPhysicsGrades = clamp(newGrade, m_minGrade, m_maxGrade);
        }
    
    
    public:

		Student(const char* newName, const char* newClass)
		{
			m_studentName = newName;
			m_studentClass = newClass;
			m_studentPhysicsGrades = 0;
		}

		Student(const char* newName, const char* newClass, unsigned int newGrade)
		{
			m_studentName = newName;
			m_studentClass = newClass;
			m_studentPhysicsGrades = clamp(newGrade, m_minGrade, m_maxGrade);
		}

		// Set the students name.
		void setName(const char* newName)
		{
			m_studentName = newName;
		}

		// Get the student's name.
		const char* getName()
		{
			return m_studentName;
		}

		// Set the student's class.
		void setClass(const char* newClass)
		{
			m_studentClass = newClass;
		}

		// Get the student's name.
		const char* getClass()
		{
			return m_studentClass;
		}

		// Get the student's grade.
		int getGrade()
		{
			return m_studentPhysicsGrades;
		}
};

class Teacher
{
	private:
		const char* m_teacherName;
		const char* m_teacherClass;
		unsigned int m_teacherEvilness;

		const uint m_minEvil = 0;
		const uint m_maxEvil = 100;
		const uint m_teacherGoodnessThreshold = 40;

	public:

		Teacher(const char* newName, const char* newClass)
		{
			srand(time(NULL));
			m_teacherName = newName;
			m_teacherClass = newClass;
			m_teacherEvilness = (rand()%100 + 1);
			m_teacherEvilness = clamp(m_teacherEvilness, m_minEvil, m_maxEvil);
		}

		Teacher(const char* newName, const char* newClass, unsigned int newEvilness)
		{
			m_teacherName = newName;
			m_teacherClass = newClass;
			m_teacherEvilness = newEvilness;
		}

		// Give the teacher a new name.
		void setName(const char* newName)
		{
			m_teacherName = newName;
		}

		// Get the teacher's name
		const char* getName()
		{
			return m_teacherName;
		}

		// Set the teacher to a new class.
		void setClass(const char* newClass)
		{
			m_teacherClass = newClass;
		}

		// Get the teacher's class.
		const char* getClass()
		{
			return m_teacherClass;
		}

		// Gambling is good kids.
		void rollEvilness()
		{
			srand(time(NULL));
		   	m_teacherEvilness = (rand()%100 + 1);
			m_teacherEvilness = clamp(m_teacherEvilness, m_minEvil, m_maxEvil);
		}

		// Give the student a grade based on the evilness score.
		void gradeStudent(Student* s)
		{
		    srand(time(NULL));
			unsigned int newScore = 0;
            
			if ( m_teacherEvilness < m_teacherGoodnessThreshold )
			{
			    newScore = rand()%(s->m_maxGrade - m_teacherEvilness) + (m_teacherGoodnessThreshold / m_teacherEvilness);
			    cout << newScore << '\n';
			    
				s->setGrade(newScore);
		    }
			else if ( m_teacherEvilness == 0 )
				s->setGrade(100);
			else
				s->setGrade(0);
		}

		// Get the evil value of the teacher.
		unsigned int getEvilness()
		{
			return m_teacherEvilness;
		}
};

int main()
{    
	Student student1("Bruhniel lamo", "Not Physics");
	Student student2("Noam the not orange cool guy", "Physics", 100);

	Teacher teacher1("Hamore hanazit shel noam", "Physics");

	std::cout << "Name: " << student1.getName() << "\nClass: " << student1.getClass() << "\nGrade: " << student1.getGrade() << "\n\n";
	std::cout << "Name: " << student2.getName() << "\nClass: " << student2.getClass() << "\nGrade: " << student2.getGrade() << "\n\n";
	std::cout << "Name: " << teacher1.getName() << "\nClass: " << teacher1.getClass() << "\nEvilness: " << teacher1.getEvilness() << "\n\n";

	teacher1.gradeStudent(&student2);
	teacher1.setName("Hamora Hamagniva");
	student1.setClass("Skipping classes");
	student2.setName("Noam with new grades");
	teacher1.setClass("Chasing students");

	std::cout << "Name: " << student1.getName() << "\nClass: " << student1.getClass() << "\nGrade: " << student1.getGrade() << "\n\n";
	std::cout << "Name: " << student2.getName() << "\nClass: " << student2.getClass() << "\nGrade: " << student2.getGrade() << "\n\n";
	std::cout << "Name: " << teacher1.getName() << "\nClass: " << teacher1.getClass() << "\nEvilness: " << teacher1.getEvilness() << "\n\n";
}
