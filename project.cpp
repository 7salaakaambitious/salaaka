#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include<time.h>
#include <ctype.h>

struct finance {
    char item_name[100];
    double item_price;
    char item_quantity[20];
    char purchase_date[20];
    char str[100];
} f[500];

int i=0;
double total = 0;
FILE *fp;

void show_menue() {
    printf("=====================================\n");
    printf("      Personal Finance System\n");
    printf("=====================================\n");
    printf("1. Add Expenses\n");
    printf("2. Expensive Item\n");
    printf("3. Cheapest Item\n");
    printf("4. Total Expenses\n");
    printf("5. Average Expenses\n");
    printf("6. Search Expenses\n");
    printf("7. Save And Exit\n");
    printf("8. Exit\n");
    printf("-------------------------------------\n");
}

void search_expenses_menue() {
    printf("=====================================\n");
    printf("      Search Expenses By:\n");
    printf("=====================================\n");
    printf("1. Date\n");
    printf("2. First alphabet\n");
    printf("3. Item name\n");
    printf("4. Price\n");
    printf("5. Back to menue\n");
    printf("-------------------------------------\n");
}

void add_items() {
            printf("Item: ");
            fgets(f[i].item_name,sizeof(f[i].item_name),stdin);
            f[i].item_name[strcspn(f[i].item_name, "\n")] = '\0';


           printf("Price: ");
           scanf("%lf",&f[i].item_price);
           getchar();

           printf("Quantity: ");
           fgets(f[i].item_quantity,sizeof(f[i].item_quantity),stdin);
           f[i].item_quantity[strcspn(f[i].item_quantity, "\n")] = '\0';

            // Step 1: Create time_t variable
            time_t t = time(NULL);

            // Step 2: Convert to local time
            struct tm tm = *localtime(&t);

            // Step 3: Format date as YYYY-MM-DD
            strftime(f[i].purchase_date, sizeof(f[i].purchase_date), "%Y-%m-%d", &tm);

           
           fprintf(fp,"Date: %s | Item: %s | Price: %.2lf | Quantity: %s\n",
            f[i].purchase_date,f[i].item_name,f[i].item_price,f[i].item_quantity);
           
            fflush(fp);  // FLUSH BUFFER IMMEDIATELY


           i++; 
    }

int load_items_from_file() {
    FILE *fp = fopen("small.txt", "r");
    if (!fp) {
        printf("Could not open file.\n");
        return 0;
    }

    int n = 0;
    while (fgets(f[n].str, sizeof(f[n].str), fp)) {
        sscanf(f[n].str,
            "Date: %10s | Item: %99[^|] | Price: %lf | Quantity: %19[^\n]",
            f[n].purchase_date,
            f[n].item_name,
            &f[n].item_price,
            f[n].item_quantity);
        n++;
        
    }

    fclose(fp);
    return n; // Return how many items were loaded
}


void expensive_item() {
     int count = load_items_from_file();
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    double maxPrice = f[0].item_price;

    // First: Find the maximum price
    for (int j = 1; j < count; j++) {
        if (f[j].item_price > maxPrice) {
            maxPrice = f[j].item_price;
        }
    }

    // Second: Print all items with that maximum price
    printf("\nItems with the highest price (%.2lf):\n", maxPrice);
    printf("----------------------------------------\n");

    for (int j = 0; j < count; j++) {
        if (f[j].item_price == maxPrice) {
            printf("Date: %s\n",f[j].purchase_date);
            printf("Item: %s\n", f[j].item_name);
            printf("Price: %.2lf\n", f[j].item_price);
            printf("Quantity: %s\n", f[j].item_quantity);
            printf("----------------------------------------\n");
        }
    }
    fclose(fp);
}

void cheapest_item() {
    int count = load_items_from_file();
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    double minPrice = f[0].item_price;
   

    for (int j = 1; j < count; j++) {
        if (f[j].item_price < minPrice) {
            minPrice = f[j].item_price;
            
        }
            
    }

    printf("\nItems with the lowest price (%.2lf):\n", minPrice);
    printf("----------------------------------------\n");

    for(int j=0; j < count; j++) {
        if (f[j].item_price == minPrice) {
    printf("Date: %s\n",f[j].purchase_date);
    printf("Item: %s\n", f[j].item_name);
    printf("Price: %.2lf\n", f[j].item_price);
    printf("Quantity: %s\n", f[j].item_quantity);
    printf("----------------------------------------\n");

        }
     }
      fclose(fp);
}

void total_item() {
    int count = load_items_from_file();
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

     total = 0;
    //int index = 0;

    for(int j=0; j<count; j++) {
        total = f[j].item_price + total ;
       // index = j;
    }
    printf("\n=======Total Expenses=======\n");
    printf("Total Expenses: %.2lf\n", total);
}

void average() {
    int count = load_items_from_file();
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    double average = total / count;
    printf("Average is %.2lf\n",average);
}

void date() {
    char searchDate[20];
    printf("Enter a date: ");
    fgets(searchDate,sizeof(searchDate),stdin);
    searchDate[strcspn(searchDate, "\n")] = '\0';
    printf("----------------------------------------\n");

    int count = load_items_from_file();
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    int found = 0;
    for(int j=0; j < count; j++) {
        if(strcmp(f[j].purchase_date,searchDate) == 0){
            printf("----------------------------------------\n");
            printf("Date: %s\n",f[j].purchase_date);
            printf("Item: %s\n", f[j].item_name);
            printf("Price: %.2lf\n", f[j].item_price);
            printf("Quantity: %s\n", f[j].item_quantity);
            printf("----------------------------------------\n");
            found = 1;
        }
    }
    if (!found) {
    printf("No expenses found for %s\n", searchDate);
    }
}
void trim(char *str) {
    // Remove leading space
    while(isspace((unsigned char)*str)) str++;

    // Remove trailing space
    char *end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    // Write new null terminator
    *(end + 1) = '\0';
}

void name() {
    char searchName[100];
    printf("Enter an item name: ");
    fgets(searchName, sizeof(searchName), stdin); 
    searchName[strcspn(searchName, "\n")] = '\0';

    int count = load_items_from_file();
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    int found = 0;
    trim(searchName);  
    for (int j = 0; j < count; j++) {
      trim(f[j].item_name);
        if(strcmp(f[j].item_name,searchName) == 0){
            printf("----------------------------------------\n");
            printf("Date: %s\n",f[j].purchase_date);
            printf("Item: %s\n", f[j].item_name);
            printf("Price: %.2lf\n", f[j].item_price);
            printf("Quantity: %s\n", f[j].item_quantity);
            printf("----------------------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No expenses found for %s\n", searchName);
    }
}

void price() {
    double searchPrice;  // INCREASED BUFFER SIZE
    printf("Enter an price: ");
    scanf("%lf",&searchPrice);
    printf("----------------------------------------\n");

    int count = load_items_from_file();
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    int found = 0;
    for (int j = 0; j < count; j++) {
        if (f[j].item_price == searchPrice) {
            printf("----------------------------------------\n");
            printf("Date: %s\n",f[j].purchase_date);
            printf("Item: %s\n", f[j].item_name);
            printf("Price: %.2lf\n", f[j].item_price);
            printf("Quantity: %s\n", f[j].item_quantity);
            printf("Date: %s\n", f[j].purchase_date);
            printf("----------------------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No expenses found for '%s'\n", searchPrice);
    }
}

void search_alphabet() {
    char inputChar;
    printf("Enter a first alphabet: ");
    scanf("%c",&inputChar);
    getchar();
    printf("----------------------------------------\n");

    int count = load_items_from_file();
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    int found = 0;
    for(int j=0; j<count; j++) {
        if(f[j].item_name[0] == inputChar) {
            printf("----------------------------------------\n");
            printf("Date: %s\n",f[j].purchase_date);
            printf("Item: %s\n", f[j].item_name);
            printf("Price: %.2lf\n", f[j].item_price);
            printf("Quantity: %s\n", f[j].item_quantity);
            printf("Date: %s\n", f[j].purchase_date);
            printf("----------------------------------------\n");
            found = 1;
        }
    }
     if (!found) {
        printf("No expenses found for '%c'\n", inputChar);
    }
}

void out() {
    exit(0);
        }

int main() {
    int choice;
    fp = fopen("small.txt","a");
    
     while (1) {
    show_menue();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

        switch (choice)
        {
        case 1:
            add_items();
            break;
        
        case 2:
            expensive_item();
            break;

        case 3:
            cheapest_item();
            break;

        case 4:
            total_item();
            break;
        
        case 5:
            average();
            break;
            
        case 6:
            int choice;
            while (1)
            {
                search_expenses_menue();
                printf("Enter your choice: ");
                scanf("%d",&choice);
                getchar();

                switch (choice)
                {
                case 1:
                    date();
                    break;
                
                case 2:
                    search_alphabet();
                    break;    

                case 3:
                    name();
                    break;
                
                case 4:
                    price();
                    break;

                case 5:
                   exit(0);
                    break;
                
                default:
                     printf(">> Invalid choice! Try again.\n");
                    break;
                }
                 
            }

        case 7:
            // Save and exit functionality would go here
            printf("Saving data...\n");
            fclose(fp);
            exit(0);
            

        case 8:
            fclose(fp);
            out(); 
            break;

        default:
            printf(">> Invalid choice! Try again.\n");
            
        }
    }
   fclose(fp);
}
