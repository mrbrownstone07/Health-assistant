# Health-assistant
cse data structure project 

Health Care Assistant


# Brief Description:  
So, we have developed a health care assistant as our project, which is basically a doctor’s appointment booking system. There are two types of account, Patient type user account and Doctor type user account. The patients will be able to search doctors who have account in the system, and will be able to book a appointment.




# Features:
   1. Patient type Account:
      1. Open an account.
      2. Searching doctors based on, Doctor’s name, Doctor’s Id, and Doctor’s near to them.
      3. Book an Appointment.


   1. Doctor type Account:
      1. Open an account.
      2. See appointment list.
      3. Go through the appointments.
      4. Remove an appointment, after the visit.




# Used Data Structures:


   1. Main Data Structure:


      a. Doctor type Data Structure: The doctor type data structure contains two hashmaps and two multi maps:
         1. Hash maps:
            A. accountMap, here we stored doctor's id as key, and doctor_type_accounts as value.
            B. loginMap, here we stored (email id + password) as key, and doctor’s id as value.
         
         2. Multi maps:
            A. nameMap, here we stored name as key, and doctor’s id as value.
            B. areaMap, here we stored (area + city) as key, and id as value.

      b. Patient type Data Structure: In this data structure we are using only a hashmap.
         1. Hash map: 
            A. accountMap, where we are (using email+key)  as key, and patient_type_account as value.


   2. Supporting data structures:


      a. Doctor List Handler: In this structure we are saving all the appointments that a patient type user has. 
      This structure is made with a unsorted linked list, because we don't need to store too many data here.
         1. Unsorted Linked List:
            A. Id_container, here we are storing the voter ids of the doctors, with whom this patient has booked an
            appointment.
 
      b. Patient List Handler: In this structure we are saving all the appointments that a doctor type user has. 
      This structure is based on a queue(Linked List based). Because, in this case we need to maintain the first come first 
      serve order.
         1. Queue:
            A. Id_container, here we are storing the voter ids of the patients, 
            that has booked an appointment with this specific doctor.
