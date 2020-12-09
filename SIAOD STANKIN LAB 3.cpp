#include <cstdio>
#include <cstdlib>
#include <clocale>


struct List
{
    List* next_el;
    char symbol;
};

void grant_access(bool*);
void input_list(List*);
List* input_next_element(List*, char);
void add_to_end(List*, char);
List* add_in_0_pos(List*, char);
List* input_in_position(List*, char, int);
void delete_last(List*);
List* delete_first(List*);
List* delete_position(List*, int);
void print_list(List*);
int calculate_lenght(List*);
void process_string(List*);
void check_error(List*);

bool ACCESS_IS_GRANTED = false;
bool* ACCESS_IS_GRANTED_POINTER = *ACCESS_IS_GRANTED;

void grant_access(*bool flag) {
    if (!flag) *flag = true;
    printf("[!]ACCESS GRANTED[!]");
}
void close_access(*bool flag) {
    if (flag) *flag = false;
    printf("[!]ACCESS CLOSED[!]");
}
bool check_access(*bool flag) {
    if (ACCESS_IS_GRANTED) return true;
    else printf("ACCESS NOT GRANTED, GRANT ACCESS TO START");
    return false;
}

List empty_list(List*, ) {
    if (check_access(ACCESS_IS_GRANTED)) {
        List* work_pointer;
        Work_pointer = ;
        while (Work_pointer != NULL)
        {
            Work_pointer = Work_pointer->next_el;
            free();
            = Work_pointer;
        }
        = NULL;
    }
    return;
}

void input_list(List* pointer)
{
    char x;
    List* current = pointer;
    printf("Input string: ");
    x = getchar();
    if (x != '\n') current->symbol = x;
    while (x != '\n')
    {
        x = getchar();
        if (x != '\n')
            current = input_next_element(current, x);
    }
}
List* input_next_element(List* current, char c)
{
    List* next = (List*)malloc(sizeof(List));
    check_error(next);
    next->symbol = c;
    next->next_el = NULL;
    return current->next_el = next;
}

void add_to_end(List* begin_pointer, char new_symbol)
{
    while (begin_pointer->next_el != NULL)
    {
        begin_pointer = begin_pointer->next_el;
    }
    List* element = (List*)malloc(sizeof(List));

    element->symbol = new_symbol;
    element->next_el = NULL;
    begin_pointer->next_el = element;
}
List* add_in_0_pos(List* begin_pointer, char new_symbol)
{
    List* element = (List*)malloc(sizeof(List));
    check_error(element);
    element->symbol = new_symbol;
    element->next_el = begin_pointer;
    return element;
}
List* input_in_position(List* begin_pointer, char new_symbol, int index_position)
{
    int lenght = calculate_lenght(begin_pointer);
    if (index_position > lenght) printf("[!]ERROR: Position > List lenght[!]\n");

    else if (index_position == 0) begin_pointer = add_in_0_pos(begin_pointer, new_symbol);

    else if (index_position == lenght) add_to_end(begin_pointer, new_symbol);

    else
    {
        List* cursor = begin_pointer;
        List* element = (List*)malloc(sizeof(List));
        check_error(element);

        for (int i = 0; i < index_position - 1; i++) cursor = cursor->next_el;
        element->symbol = new_symbol;
        element->next_el = cursor->next_el;
        cursor->next_el = element;
    }
    return begin_pointer;
}

void delete_last(List* begin_pointer)
{
    List* previous_element = NULL;
    List* cursor = begin_pointer;
    if (cursor != NULL)
    {
        while (cursor->next_el != NULL)
        {
            previous_element = cursor;
            cursor = cursor->next_el;
        }
        free(cursor);
        if (previous_element != NULL) previous_element->next_el = NULL;


    }

}
List* delete_first(List* begin_pointer)
{
    List* second = begin_pointer->next_el;
    free(begin_pointer);
    begin_pointer = second;
    return begin_pointer;

}
List* delete_position(List* begin_pointer, int index_position)
{
    int lenght = calculate_lenght(begin_pointer);
    if (index_position >= lenght) printf("Del position > List lenght\n");

    else if (index_position == lenght) delete_last(begin_pointer);

    else if (index_position == 0) begin_pointer = delete_first(begin_pointer);

    else
    {
        List* cursor = begin_pointer;
        for (int i = 0; i < index_position - 1; i++) cursor = cursor->next_el;
        List* temp = cursor->next_el;
        cursor->next_el = temp->next_el;
        free(temp);
    }
    return begin_pointer;
}

void print_list(List* begin_pointer)
{
    check_error(begin_pointer);
    printf("string: ");
    while (begin_pointer != NULL) {
        printf("%c", begin_pointer->symbol);
        begin_pointer = begin_pointer->next_el;
    }
}
int calculate_lenght(List* begin_pointer)
{
    int i = 1;
    for (i; begin_pointer->next_el != NULL; i++) begin_pointer = begin_pointer->next_el;
    return i;
}
void process_string(List* begin_pointer)
{
    int counter = 0;
    bool contains_five_e = false;
    List* cursor = begin_pointer;
    while (cursor->next_el != NULL)
    {
        if (cursor->symbol == 'e' || cursor->symbol == 'E') counter++;
        else
            if (counter >= 5)
            {
                contains_five_e = true;
                break;
            }
            else(counter = 0);
        cursor = cursor->next_el;
    }
    if (contains_five_e) printf("this string contains 5 or more e");
    else printf("this string contains less than 5 e");
}
void check_error(List* pointer) {
    if (pointer == NULL)
    {
        printf("[!]MEMORY ALLOCATION ERROR[!]\n");
        exit(0);
    }
}



int main()
{
    int menu, position;
    char symbol;
    List* begin_pointer = (List*)malloc(sizeof(List));
    check_error(begin_pointer);
    input_list(begin_pointer);
    while (true) {
        printf("\n----------------\n \
            Menu:\n\n \
            1)Grant access\n \
            2)Empty list\n \
            3)Check if list is empty\n \
            4)Set work pointer on begin of list\n \
            5)Check if work pointer on end of list\n \
            6)Move work pointer to next element\n \
            7)Print element next from work pointer\n \
            8)Delete element next from work pointer\n \
            9)Cut element next from work pointer\n \
            10)Edit element next from work pointer\n \
            11)Add element next from work pointer\n \
            12)Process string\n \
            13)Print\n \
            14)Close access\n \
            \n----------------\n");
        scanf("%d", &menu);

        if (menu == 1) { grant_access(ACCESS_IS_GRANTED_POINTER); }

        if (menu == 2) { empty_list(); }

        if (menu == 1) {
            printf("input add position:");
            scanf("%d", &position);
            printf("input add element:");
            scanf("%s", &symbol);
            begin_pointer = input_in_position(begin_pointer, symbol, position);
        }
        if (menu == 2) {
            printf("input del element position:");
            scanf("%d", &position);
            begin_pointer = delete_position(begin_pointer, position);
        }
        if (menu == 12) process_string(begin_pointer);
        if (menu == 13) print_list(begin_pointer);
        if (menu == 14) close_access(ACCESS_IS_GRANTED_POINTER);
    }
}