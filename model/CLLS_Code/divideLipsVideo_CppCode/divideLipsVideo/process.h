#include <iostream>  
#include <fstream>  
#include "json/json.h"
#include <opencv2\opencv.hpp>  
#include <direct.h>
#include <io.h>
#include <stdio.h>

#include <dlib/opencv.h>  
#include <opencv2/opencv.hpp>  
#include <dlib/image_processing/frontal_face_detector.h>  
#include <dlib/image_processing/render_face_detections.h>  
#include <dlib/image_processing.h>  
#include <dlib/gui_widgets.h>  

using namespace dlib;
using namespace std;

long int string_to_int(string snum); //�����ַ���ת��������
string TCHAR2STRING(TCHAR *STR); //TCHAR����תstring����
int video_cut(long int bg, long int ed, string filename, frontal_face_detector detector, shape_predictor pose_model); //��Ƶ���к���
int lip_process(); //�������ݲɼ�������

string videopath; //��Ƶ��·��
string videoname; //��Ƶ��
string jsonpath; //����תдjson���ݴ�·��
string savepath; //���ݱ���·��