#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<string> browserHistory;
    int choice;
    string url;

    do {
        cout << "\n=========================================\n";
        cout << "    BROWSER HISTORY STACK SYSTEM (LIFO)   \n";
        cout << "=========================================\n";
        cout << "1. Visit New Page (Push)\n";
        cout << "2. Go Back / Close Page (Pop)\n";
        cout << "3. View Current Page (Top)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter website URL (e.g., github.com): ";
                cin >> url;
                browserHistory.push(url);
                cout << "[Success] Visited and pushed: " << url << "\n";
                break;

            case 2:
                if (browserHistory.empty()) {
                    cout << "[Error] Stack Underflow! History is completely empty.\n";
                } else {
                    cout << "[Action] Leaving page: " << browserHistory.top() << "\n";
                    browserHistory.pop();
                    if (!browserHistory.empty()) {
                        cout << "[Current] Returned to active page: " << browserHistory.top() << "\n";
                    } else {
                        cout << "[Current] Back to browser home (History is now empty).\n";
                    }
                }
                break;

            case 3:
                if (browserHistory.empty()) {
                    cout << "[Info] Browser history is currently empty.\n";
                } else {
                    cout << "[Info] Current Active Page (Top of Stack): " << browserHistory.top() << "\n";
                }
                break;

            case 4:
                cout << "Exiting Browser History Simulator. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}
