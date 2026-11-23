class ProductOfNumbers {
private:
    vector<int> accumulator;

    void reset() {
        this->accumulator = vector<int>({1});
    }

    int getAccumulator(int k) {
        int i = this->accumulator.size() - k - 1;
        return this->accumulator[i];
    }

public:
    ProductOfNumbers() {
        this->reset();    
    }
    
    void add(int num) {
        if (num == 0) {
            this->reset();
        }
        else {
            this->accumulator.push_back(num * this->getAccumulator(0));
        }
    }
    
    int getProduct(int k) {
        if (this->accumulator.size() <= k) {
            return 0;
        }
        return this->getAccumulator(0) / this->getAccumulator(k);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
 