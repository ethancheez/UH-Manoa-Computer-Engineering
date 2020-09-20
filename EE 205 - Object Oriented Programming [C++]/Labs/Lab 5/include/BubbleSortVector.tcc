template <typename T>
void BubbleSortVector<T>::sort() {

    for(int i = 0; i < this->size()-1; i++) {
        for(int j = 0; j < this->size()-i-1; j++) {
            if( (*this)[j] > (*this)[j+1] ) {
                T temp = (*this)[j];
                (*this)[j] = (*this)[j+1];
                (*this)[j+1] = temp;
            }
        }
    }
}
