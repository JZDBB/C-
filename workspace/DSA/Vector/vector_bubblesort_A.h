
#pragma once

template <typename T> //�������������򣨻����棩
void Vector<T>::bubbleSort3( Rank lo, Rank hi ) { //assert: 0 <= lo < hi <= size
   while( lo < --hi ) //��������ɨ��
      for( Rank i = lo; i < hi; i++ ) //����������Ԫ��
         if( _elem[i] > _elem[i + 1] ) //��������
            swap( _elem[i], _elem[i + 1] ); //������ʹ�ֲ�����
}