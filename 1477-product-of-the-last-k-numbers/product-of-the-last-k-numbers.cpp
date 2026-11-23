class ProductOfNumbers {
public:
    vector<int> prefixProduct;
    ProductOfNumbers() {
        prefixProduct.push_back(1);
    }
    
    void add(int num) {
        if(num>0){
            prefixProduct.push_back(num*prefixProduct.back());
        }
        else{
            prefixProduct = {1};
        }
    }
    int getProduct(int k) {
        if(k>=prefixProduct.size()){
            return 0;
        }
        else{
            return prefixProduct.back()/prefixProduct[prefixProduct.size()-k-1];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */