//
// Created by HP on 27/05/2024.
//

#ifndef SUPPLIERORDERVIEW_H
#define SUPPLIERORDERVIEW_H

#include <iostream>
#include "SupplierOrder.h"
#include "View.h"
#include "SupplierOrderContainer.h"

        class SupplierOrder{
        public:
        SupplierOrder getSupplierOrder();
        string getSupplierName();
        string getMenuName();
        string getAmountInStock();
        void printSupplierOrdersBySupplier(SupplierOrderConstainer& supplierOrders, Supplier& supplier);
        void printAllSupplierOrders(SupplierOrderContainer& supplierOrders);
        void OrderPlaced();
        void ThereAreNoOrders();
};
#endif //SUPPLIERORDERVIEW_H
