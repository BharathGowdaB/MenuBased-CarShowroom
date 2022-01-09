The program is menu-based application.

Program requires TurboC to compile and run. 

Options :

* Main-UI : 
	The program starts with Main-UI where the user has 3 options
	1) Adminstration Access :  Only for Owners, Admin or Authorized person, 
		to perform operations like add new car, accept/reject an order request
	2) Customer Access : For Customers to view car list and place order
	3) Exit : Exit the program

* Admin-UI :
	Inferface for administrative purpose :
	1) Available Car List : list cars currently available in the showroom
	2) Pending Orders : list of requested orders placed by customers
	3) Last Sold Car : last car delivered(order accepted) 
	4) Add New Car : add a new car to available car list
	5) Back : back to main menu

* Customer-UI :
	Interface for Customer use :
	1) Available Car List : view list cars currently available in the showroom,
		Here customer is allowed to place order using car number
	2) Back : go back to main menu

Module :

* Initialization :
	This function is optional, whose purpose is to add some values into car-list, order-list

* Display-Car-List : (Available Car list)
	The cars are stored in a linked list. 
	The above function traverses the list the display the car name along with quantity of that car

* Pending-Orders :
	The orders are also stored in linked list
	The above function is executed an admin chooses pending order in admin menu
	It retrives first element(car name) in the order list and gives option of accept or reject
	if accept : the first element(car name) in the order is removed and assigned to last-car-sold, 
		indicating that the car was delivered to requested customer. 
		Also the quantity of the sold car is decremented by 1
	if reject : the first element(car name) in the order is removed

* Dequeue : 
	decrement quantity of a car by 1, if the quantity of the car becomes 0 remove the car from list

* Add-Car :
	Add a new Car to the list and sent it quantity to 1
	If the car if already in the list then increment its quantity by 1 instead of adding