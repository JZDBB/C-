
template <typename T> //����������������ǰ��ֹ�棩
void Vector<T>::bubbleSort2( Rank lo, Rank hi ) { //assert: 0 <= lo < hi <= size
   for( bool sorted = false; sorted = !sorted; )
      for( Rank i = lo; i < hi - 1; i++ )
         if( _elem[i] > _elem[i + 1] ) //��������
            swap( _elem[i], _elem[i + 1] ), sorted = false;
            //������ʹ�ֲ����򡪡���Ȼ�����˻�����ȷ������������
}
