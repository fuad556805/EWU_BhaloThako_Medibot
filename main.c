#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int timeToSeconds(char *time)
{
    int hours, minutes, seconds;
    sscanf(time, "%d:%d:%d", &hours, &minutes, &seconds);
    return hours * 3600 + minutes * 60 + seconds;
}

void patientDetails(char name[], char gender[], int *age, float *weight, float *height, float *heartRate, float *bloodPressure, float *temperature)
{
    printf("\n==== Enter Patient Details ====\n");
    printf("Name: ");
    scanf(" %[^\n]", name);
    printf("Gender (Male/Female/Other): ");
    scanf(" %[^\n]", gender);
    printf("Age: ");
    scanf("%d", age);
    printf("Weight (kg): ");
    scanf("%f", weight);
    printf("Height (m): ");
    scanf("%f", height);
    printf("Heart Rate (bpm): ");
    scanf("%f", heartRate);
    printf("Blood Pressure (mmHg): ");
    scanf("%f", bloodPressure);
    printf("Body Temperature (Fahrenheit): ");
    scanf("%f", temperature);

    printf("\nPatient Name: %s\nGender: %s\nAge: %d years\nWeight: %.2f kg\nHeight: %.2f m\nHeart Rate: %.2f bpm\nBlood Pressure: %.2f mmHg\nBody Temperature: %.2f°F\n",
           name, gender, *age, *weight, *height, *heartRate, *bloodPressure, *temperature);
}

float calculateBMI(float weight, float height)
{
    return weight / (height * height);
}

void healthCheck(float weight, float height, float heartRate, float bloodPressure, float temperature)
{
    float bmi = calculateBMI(weight, height);
    float normalBP_low = 90.0, normalBP_high = 120.0;
    float normalHR_low = 60.0, normalHR_high = 100.0;
    float normalTemp_low = 97.0, normalTemp_high = 99.0;

    printf("\n==== Health Check ====\n");
    printf("Your BMI: %.2f\n", bmi);

    if (bmi < 18.5)
    {
        printf("Advice: You are underweight. Eat nutritious food.\n");
    }
    else if (bmi >= 18.5 && bmi < 24.9)
    {
        printf("Advice: Your weight is normal. Maintain a healthy lifestyle.\n");
    }
    else if (bmi >= 25 && bmi < 29.9)
    {
        printf("Advice: You are overweight. Exercise regularly.\n");
    }
    else
    {
        printf("Advice: You are obese. Consult a doctor.\n");
    }

    printf("\nNormal Blood Pressure: %.2f - %.2f mmHg\n", normalBP_low, normalBP_high);
    if (bloodPressure >= normalBP_low && bloodPressure <= normalBP_high)
    {
        printf("Your BP is normal.\n");
    }
    else
    {
        printf("Your BP is NOT normal: Sit or lie down, stay calm, drink water, avoid salt, and seek medical help.\n");
    }

    printf("\nNormal Heart Rate: %.2f - %.2f bpm\n", normalHR_low, normalHR_high);
    if (heartRate >= normalHR_low && heartRate <= normalHR_high)
    {
        printf("Your Heart Rate is normal.\n");
    }
    else
    {
        printf("Your Heart Rate is NOT normal: Stay calm, breathe deeply, drink cold water, and see a doctor if it happens often.\n");
    }

    printf("\nNormal Body Temperature: %.2f - %.2f°F\n", normalTemp_low, normalTemp_high);
    if (temperature >= normalTemp_low && temperature <= normalTemp_high)
    {
        printf("Your Body Temperature is normal.\n");
    }
    else
    {
        printf("Your Body Temperature is NOT normal.\n");
        if (temperature > normalTemp_high)
        {
            printf("Remedy: You may have a fever. Rest, drink plenty of fluids, and take paracetamol if necessary.\n");
        }
        else if (temperature < normalTemp_low)
        {
            printf("Remedy: You may have hypothermia. Keep warm, drink warm fluids, and seek medical attention if symptoms persist.\n");
        }
    }
}

void checkSymptoms()
{
    char symptoms[11][50] =
    {
        "Cold", "Cough", "Fever", "Headache", "Body Pain",
        "Sore Throat", "Nausea", "Stomach Pain", "Diarrhea", "Skin Rash", "Shortness of Breath"
    };
    int userSymptoms[11] = {0};
    int count = 0;

    printf("\n==== Check Your Symptoms ====\n");
    for (int i = 0; i < 11; i++)
    {
        printf("%d. %s\n", i + 1, symptoms[i]);
    }
    printf("Enter the numbers of your symptoms (example: 1 3 5 and end with -1): ");

    int input;
    while (1)
    {
        scanf("%d", &input);
        if (input == -1)
            break;
        if (input >= 1 && input <= 11)
        {
            userSymptoms[input - 1] = 1;
            count++;
        }
    }

    if (count == 0)
    {
        printf("\nNo symptoms entered. Please try again.\n");
        return;
    }

    printf("\n==== Possible Diseases ====\n");

    int matchFound = 0;

    if (userSymptoms[0] && userSymptoms[1] && userSymptoms[5])
    {
        printf("\n1. Common Cold\n");
        printf("Remedy: Drink warm water, take steam, rest, consume honey and ginger tea, gargle with salt water, eat vitamin C-rich foods\n");
        printf("Medicine: Cetirizine\n");
        printf("Doctor: General Physician\n");
        matchFound = 1;
    }

    if (userSymptoms[2] && userSymptoms[3] && userSymptoms[4])
    {
        printf("\n2. Flu\n");
        printf("Remedy: Rest, stay hydrated, drink herbal teas, use a humidifier, eat nutrient-rich foods, avoid cold drinks\n");
        printf("Medicine: Paracetamol\n");
        printf("Doctor: General Physician\n");
        matchFound = 1;
    }

    if (userSymptoms[3] && userSymptoms[6])
    {
        printf("\n3. Migraine\n");
        printf("Remedy: Dark room, cold compress, avoid strong odors, practice deep breathing, maintain a regular sleep schedule, reduce screen time\n");
        printf("Medicine: Ibuprofen\n");
        printf("Doctor: Neurologist\n");
        matchFound = 1;
    }

    if (userSymptoms[7] && userSymptoms[8])
    {
        printf("\n4. Food Poisoning\n");
        printf("Remedy: Hydrate, bland diet, avoid dairy and spicy foods, consume probiotics like yogurt, rest well, avoid caffeine\n");
        printf("Medicine: ORS\n");
        printf("Doctor: Gastroenterologist\n");
        matchFound = 1;
    }

    if (userSymptoms[2] && userSymptoms[9])
    {
        printf("\n5. Dengue Fever\n");
        printf("Remedy: Rest, fluids, drink papaya leaf juice, use mosquito repellent, avoid aspirin, maintain good hygiene\n");
        printf("Medicine: Paracetamol\n");
        printf("Doctor: Medicine Specialist\n");
        matchFound = 1;
    }

    if (userSymptoms[10] && userSymptoms[2])
    {
        printf("\n6. Asthma/COVID-19\n");
        printf("Remedy: Isolate, monitor oxygen, practice breathing exercises, avoid cold air, stay in a well-ventilated room, stay hydrated\n");
        printf("Medicine: Inhaler\n");
        printf("Doctor: Pulmonologist\n");
        matchFound = 1;
    }

    if (userSymptoms[5] && userSymptoms[2])
    {
        printf("\n7. Tonsillitis\n");
        printf("Remedy: Salt water gargle, drink warm herbal tea, eat soft foods, avoid smoking, take lozenges, rest well\n");
        printf("Medicine: Antibiotics\n");
        printf("Doctor: ENT Specialist\n");
        matchFound = 1;
    }

    if (userSymptoms[6] && userSymptoms[8])
    {
        printf("\n8. Gastroenteritis\n");
        printf("Remedy: BRAT diet, drink plenty of fluids, avoid fatty foods, consume ginger tea, take probiotics, rest properly\n");
        printf("Medicine: Antidiarrheal\n");
        printf("Doctor: Gastroenterologist\n");
        matchFound = 1;
    }

    if (userSymptoms[1] && userSymptoms[10])
    {
        printf("\n9. Bronchitis\n");
        printf("Remedy: Steam inhalation, drink warm fluids, avoid smoke, practice controlled coughing, stay in a moist environment\n");
        printf("Medicine: Cough syrup\n");
        printf("Doctor: Pulmonologist\n");
        matchFound = 1;
    }

    if (userSymptoms[0] && userSymptoms[3])
    {
        printf("\n10. Sinusitis\n");
        printf("Remedy: Warm compress, use a saline nasal spray, drink hot soups, avoid allergens, take steam therapy\n");
        printf("Medicine: Decongestant\n");
        printf("Doctor: ENT Specialist\n");
        matchFound = 1;
    }

    if (userSymptoms[9] && userSymptoms[10])
    {
        printf("\n11. Allergic Reaction\n");
        printf("Remedy: Avoid allergens, use a cool compress, take a lukewarm bath, keep surroundings dust-free, consume vitamin C-rich foods\n");
        printf("Medicine: Antihistamine\n");
        printf("Doctor: Allergist\n");
        matchFound = 1;
    }

    if (!matchFound)
    {
        for (int i = 0; i < 11; i++)
        {
            if (userSymptoms[i])
            {
                printf("\nBased on your first symptom (%s), you may have:\n", symptoms[i]);
                switch (i + 1)
                {
                case 1:
                    printf("Possible Condition: Common Cold\n");
                    printf("Remedy: Drink warm water, take steam, rest, consume honey and ginger tea, take vitamin C-rich foods like oranges, and keep yourself warm.\n");
                    break;
                case 2:
                    printf("Possible Condition: Bronchitis\n");
                    printf("Remedy: Steam inhalation, drink herbal tea, avoid cold drinks, use a humidifier, and take honey with warm water.\n");
                    break;
                case 3:
                    printf("Possible Condition: Viral Fever\n");
                    printf("Remedy: Rest, stay hydrated, take paracetamol for fever, eat light meals, and use a cold compress on the forehead.\n");
                    break;
                case 4:
                    printf("Possible Condition: Tension Headache\n");
                    printf("Remedy: Rest in a quiet room, massage your temples, practice deep breathing, reduce screen time, and stay hydrated.\n");
                    break;
                case 5:
                    printf("Possible Condition: Muscle Strain\n");
                    printf("Remedy: Apply a warm compress, rest the affected area, perform gentle stretching, use pain-relieving ointments, and massage lightly.\n");
                    break;
                case 6:
                    printf("Possible Condition: Pharyngitis\n");
                    printf("Remedy: Salt water gargle, drink warm herbal tea, use lozenges, avoid cold drinks, and keep your throat moist.\n");
                    break;
                case 7:
                    printf("Possible Condition: Indigestion\n");
                    printf("Remedy: Drink ginger tea, eat smaller meals, avoid oily foods, chew food properly, and walk for a few minutes after meals.\n");
                    break;
                case 8:
                    printf("Possible Condition: Gastritis\n");
                    printf("Remedy: Avoid spicy food, eat small frequent meals, drink coconut water, take probiotics like yogurt, and reduce stress.\n");
                    break;
                case 9:
                    printf("Possible Condition: Gastroenteritis\n");
                    printf("Remedy: Drink ORS, avoid dairy products, eat bananas and rice, stay hydrated, and take probiotics.\n");
                    break;
                case 10:
                    printf("Possible Condition: Allergic Reaction\n");
                    printf("Remedy: Apply calamine lotion, avoid allergens, take antihistamines, keep the affected area cool, and wear loose clothing.\n");
                    break;
                case 11:
                    printf("Possible Condition: Asthma\n");
                    printf("Remedy: Use an inhaler, practice deep breathing, avoid dust and smoke, stay indoors during high pollen times, and maintain good air ventilation.\n");
                    break;
                }
                break;
            }
        }
    }
}


void setReminder()
{
    char medicine[50], time[10];

    printf("\n==== Set Medicine Reminder ====\n");
    printf("Medicine Name: ");
    scanf(" %[^\n]", medicine);
    printf("Time (HH:MM:SS): ");
    scanf(" %[^\n]", time);

    int totalSeconds = timeToSeconds(time);

    printf("\nReminder set: Take %s after %s.\n", medicine, time);

    printf("\nCountdown to reminder...\n");
    for (int i = totalSeconds; i > 0; i--)
    {
        printf("%d seconds remaining...\n", i);
        sleep(1);
    }

    printf("\nNOTIFICATION: Don't forget to take %s now!\n", medicine);
}

void showDoctorDetails()
{
    char area[50];
    printf("\n==== Doctor & Hospital Details ====\n");
    printf("Enter the area name (Aftabnagar/Rampura/Banasree/Badda): ");
    scanf(" %[^\n]", area);

    printf("\n==== Hospitals in %s ====\n", area);

    if (strcmp(area, "Aftabnagar") == 0)
    {
        printf("Hospital Name: Nagorik Hospital\n");
        printf("Address: House #59, Block-C, Main Road, Aftabnagar, Dhaka-1212\n");
        printf("Contact Number: +8809600 990000\n");
    }
    else if (strcmp(area, "Rampura") == 0)
    {
        printf("Hospital Name: Farazy Hospital Ltd.\n");
        printf("Address: House #15-19, Block-E, Main Road, Banasree, Rampura, Dhaka-1219\n");
        printf("Contact Number: +8801766111317\n");

        printf("\nHospital Name: Better Life Hospital\n");
        printf("Address: 1, Sahid Muktijoddha Faruk Iqbal and Taslim Road, Rampura, Dhaka-1219\n");
        printf("Contact Number: +8809606990000\n");

        printf("\nHospital Name: Bangladesh Multicare Hospital Ltd.\n");
        printf("Address: 382, DIT Road, West Rampura, Dhaka-1219\n");
        printf("Contact Number: +8801321147333\n");

        printf("\nHospital Name: Bangladesh Fertility Hospital Ltd.\n");
        printf("Address: Plot 10, Block E, Banasree Main Road, Rampura, Dhaka-1219\n");
        printf("Contact Number: +880189477811\n");

        printf("\nHospital Name: Unity Aid Hospital Ltd.\n");
        printf("Address: House #1-2, Block D, Main Road, South Banasree, Rampura, Dhaka-1219\n");
        printf("Contact Number: +8801997421112\n");

        printf("\nHospital Name: Advance Hospital\n");
        printf("Address: House #1, Main Road, Block F, Banasree, Rampura, Dhaka-1219\n");
        printf("Contact Number: +8801873242424\n");

        printf("\nHospital Name: Famous Specialized Hospital\n");
        printf("Address: House #05, Block-H, Main Road, Rampura, Dhaka-1219\n");
        printf("Contact Number: +8801711612103\n");
    }
    else if (strcmp(area, "Banasree") == 0)
    {
        printf("Hospital Name: Al Razi Islamia Hospital\n");
        printf("Address: House #09, Block-G, Main Road, Banasree, Rampura, Dhaka-1219\n");
        printf("Contact Number: +8801772444777\n");

        printf("\nHospital Name: Dristi Eye Hospital Banasree Ltd.\n");
        printf("Address: 48, Road 3/A, Block E, Rampura Banasree, Dhaka-1219\n");
        printf("Contact Number: +8801988815741\n");
    }
    else if (strcmp(area, "Badda") == 0)
    {
        printf("Hospital Name: AMZ Hospital Ltd.\n");
        printf("Address: North Badda, Dhaka-1212\n");
        printf("Contact Number: +8801777770990\n");

        printf("\nHospital Name: Badda General Hospital\n");
        printf("Address: Uttar Badda, Progoti Sarani, Rampura, Dhaka-1212\n");
        printf("Contact Number: +8801790776722\n");
    }
    else
    {
        printf("No hospitals found in the specified area.\n");
    }
}

int main()
{
    int choice;
    char name[50], gender[10];
    int age = 0;
    float weight = 0.0, height = 0.0, heartRate = 0.0, bloodPressure = 0.0, temperature = 0.0;

    while (1)
    {
        printf("\n======= BhaloThako MediBot EWU =======\n");
        printf("1. Enter Patient Details\n");
        printf("2. Health Check\n");
        printf("3. Check Symptoms for Diseases\n");
        printf("4. Set Medicine Reminder\n");
        printf("5. Doctor & Hospital Details\n");
        printf("6. Exit\n");
        printf("\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            patientDetails(name, gender, &age, &weight, &height, &heartRate, &bloodPressure, &temperature);
            break;
        case 2:
            if (age == 0)
            {
                printf("\nPlease enter patient details first (Option 1).\n");
            }
            else
            {
                healthCheck(weight, height, heartRate, bloodPressure, temperature);
            }
            break;
        case 3:
            checkSymptoms();
            break;
        case 4:
            setReminder();
            break;
        case 5:
            showDoctorDetails();
            break;
        case 6:
            printf("\nExiting...\n");
            exit(0);
        default:
            printf("\nInvalid input! Choose 1-6.\n");
        }
    }

    return 0;
}
