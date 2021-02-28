// LoadData.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCtest1.h"
#include "LoadData.h"
#include "afxdialogex.h"
#include "process.h"
//#include "ResultShow.h"
#include "MFCtest1Dlg.h"


// LoadData �Ի���

IMPLEMENT_DYNAMIC(LoadData, CDialogEx)

LoadData::LoadData(CWnd* pParent /*=NULL*/)
	: CDialogEx(LoadData::IDD, pParent)
{

}

LoadData::~LoadData()
{
}

void LoadData::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LoadData, CDialogEx)
	ON_BN_CLICKED(IDC_VIDEO_BUTTON1, &LoadData::OnBnClickedVideoButton1)
	ON_BN_CLICKED(IDC_JSON_BUTTON2, &LoadData::OnBnClickedJsonButton2)
	ON_BN_CLICKED(IDC_PROCESS_BUTTON4, &LoadData::OnBnClickedProcessButton4)
	ON_BN_CLICKED(IDC_PROCESS_BUTTON5, &LoadData::OnBnClickedProcessButton5)
	ON_BN_CLICKED(IDC_MENU1_BUTTON1, &LoadData::OnBnClickedMenu1Button1)
	ON_BN_CLICKED(IDC_EXIT1_BUTTON2, &LoadData::OnBnClickedExit1Button2)
END_MESSAGE_MAP()



// LoadData ��Ϣ�������


void LoadData::OnBnClickedVideoButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	// ���ù�����   
	TCHAR szFilter1[] = _T("��Ƶ�ļ�(*.mp4)|*.mp4|�����ļ�(*.*)|*.*||");
	// ������ļ��Ի���   
	CFileDialog fileDlg(TRUE, _T("mp4"), NULL, 0, szFilter1, this);
	CString strFilePath1, fileName;

	// ��ʾ���ļ��Ի���
	if (IDOK == fileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����  
		strFilePath1 = fileDlg.GetPathName();
		//SetDlgItemText(IDC_VIDEO_EDIT1, strFilePath1);
		//string videopath1 = CT2A(strFilePath1.GetBuffer());
		videopath = CT2A(strFilePath1.GetBuffer());
		fileName = fileDlg.GetFileName();
		videoname = CT2A(fileName.GetBuffer());
		SetDlgItemText(IDC_VIDEO_EDIT1, fileName);
		TCHAR Result1[] = _T("��Ƶ���سɹ���");
		SetDlgItemText(IDC_RESULT_EDIT2, Result1); //��ʾ������
	}
}


void LoadData::OnBnClickedJsonButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	// ���ù�����  
	TCHAR szFilter2[] = _T("����תд�ļ�(*.json)|*.json|�����ļ�(*.*)|*.*||");
	// ������ļ��Ի���   
	CFileDialog fileDlg2(TRUE, _T("json"), NULL, 0, szFilter2, this);
	CString strFilePath2;

	// ��ʾ���ļ��Ի���
	if (IDOK == fileDlg2.DoModal())
	{
		// ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����  
		strFilePath2 = fileDlg2.GetPathName();
		//SetDlgItemText(IDC_JSON_EDIT2, strFilePath2);
		jsonpath = CT2A(strFilePath2.GetBuffer());
		TCHAR Result1[] = _T("����תдjson���ݼ��سɹ���");
		SetDlgItemText(IDC_RESULT_EDIT2, Result1); //��ʾ������
	}
}


void LoadData::OnBnClickedProcessButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileFind finder;
	//CString path;
	//BOOL fileExist;

	// ��ȡ�ض��ļ��е�LPITEMIDLIST�����Խ�֮���ΪHANDLE  
	// ��ν���ض��ļ���,�������CSIDL_XXX������֮��  
	LPITEMIDLIST rootLoation;
	SHGetSpecialFolderLocation(NULL, CSIDL_DESKTOP, &rootLoation);
	if (rootLoation == NULL) {
		// unkown error  
		return;
	}
	// ���öԻ���  
	BROWSEINFO bi;
	ZeroMemory(&bi, sizeof(bi));
	bi.pidlRoot = rootLoation; // �ļ��жԻ���֮��Ŀ¼����ָ���Ļ���Ϊ�ҵĵ���  
	bi.lpszTitle = _T("��ѡ�񱣴����ݵ��ļ���"); // ��ʾѡ���ļ�����·��  
	// bi.ulFlags = BIF_EDITBOX | BIF_RETURNONLYFSDIRS;  

	// �򿪶Ի���, �е���DoModal  
	LPITEMIDLIST targetLocation = SHBrowseForFolder(&bi);
	if (targetLocation != NULL) {
		TCHAR targetPath[MAX_PATH];
		SHGetPathFromIDList(targetLocation, targetPath);
		//MessageBox( targetPath );  
		savepath = TCHAR2STRING(targetPath);  //��·����ŵ�savepath�ַ���
		//SetDlgItemText(IDC_SAVEPATH_EDIT1, targetPath); //��·����ʾ
		TCHAR Result1[] = _T("���ݱ���·����ȡ�ɹ���");
		SetDlgItemText(IDC_RESULT_EDIT2, Result1); //��ʾ������
	}
}


//json��������Ƶ�����Լ�������ȡ


long int string_to_int(string snum) //string����ת������
{
	stringstream ss;//������
	ss << snum;    //�ַ��������
	long int num;
	ss >> num;    //���뵽����
	return num;
}

string TCHAR2STRING(TCHAR *STR) //TCHAR����תstring����
{

	int iLen = WideCharToMultiByte(CP_ACP, 0, STR, -1, NULL, 0, NULL, NULL);
	char* chRtn = new char[iLen*sizeof(char)];
	WideCharToMultiByte(CP_ACP, 0, STR, -1, chRtn, iLen, NULL, NULL); //���ֽ�ת���ֽ�
	std::string str(chRtn);
	return str;
}

/*��Ƶ�и��봽�ηָ��*/
int video_cut(long int bg, long int ed, string filename, frontal_face_detector detector, shape_predictor pose_model)
{
	if (bg == ed) return 0;//ȥ��json�ļ���������еı�����

	//��1��������Ƶ
	string tss;
	tss = videopath;
	cv::VideoCapture capture(videopath);
	cv::Mat inframe;//����һ��Mat���������ڴ洢ÿһ֡��ͼ��
	if (!capture.isOpened()){
		return 0;
	}
	int rate = capture.get(CV_CAP_PROP_FPS);
	int delay = 1000 / rate;
	//cout << "֡�ʣ�" << rate << endl;
	capture.read(inframe);
	//capture >> inframe;  //��ȡ��ǰ֡

	//���������ļ���
	char pathdir[80];
	char str1[80];
	char cfilename[80];
	strcpy_s(cfilename,filename.c_str());
	int len = strlen(cfilename); //�жϴ����ǵ��ֻ���˫�ֻ򳤴���
	int num = 1; //��ͬ���Ĵ������򴴽��ļ���
	strcpy_s(str1, savepath.c_str());
	if (len < 4){
		while (true)
		{
			if (num < 10)
				sprintf_s(pathdir, "%s%s%s%s%d", str1, "\\����\\", filename, "_100", num);
			else if (num < 100)
				sprintf_s(pathdir, "%s%s%s%s%d", str1, "\\����\\", filename, "_10", num);
			else
				sprintf_s(pathdir, "%s%s%s%s%d", str1, "\\����\\", filename, "_1", num);
			if (_access(pathdir, 0) == -1){
				//int ts = 1;
				//cout << "�´����ļ��У�" << filename << endl;
				_mkdir(pathdir); //�����ļ���
				break;
			}
			num++;
		}
	}
	else if (len > 4)
	{
		while (true)
		{
			if (num < 10)
				sprintf_s(pathdir, "%s%s%s%s%d", str1, "\\������\\", filename, "_100", num);
			else if(num < 100)
				sprintf_s(pathdir, "%s%s%s%s%d", str1, "\\������\\", filename, "_10", num);
			else
				sprintf_s(pathdir, "%s%s%s%s%d", str1, "\\������\\", filename, "_1", num);
			if (_access(pathdir, 0) == -1){
				//int ts = 1;
				//cout << "�´����ļ��У�" << filename << endl;
				_mkdir(pathdir); //�����ļ���
				break;
			}
			num++;
		}
	}
	else
	{
		while (true)
		{
			if (num < 10)
				sprintf_s(pathdir, "%s%s%s%s%d", str1, "\\˫��\\", filename, "_100", num);
			else if (num < 100)
				sprintf_s(pathdir, "%s%s%s%s%d", str1, "\\˫��\\", filename, "_10", num);
			else
				sprintf_s(pathdir, "%s%s%s%s%d", str1, "\\˫��\\", filename, "_1", num);
			if (_access(pathdir, 0) == -1){
				//int ts = 1;
				//cout << "�´����ļ��У�" << filename << endl;
				_mkdir(pathdir); //�����ļ���
				break;
			}
			num++;
		}
	}
	//sprintf_s(pathdir, "%s%s", "C:\\Users\\Jordan23\\Desktop\\DataSet\\", filename);
	//string path; path.c_str�ǽ�stringתΪchar *

	//���������ļ���
	sprintf_s(str1, "%s%s", pathdir, "\\lip_images");
	if (_access(str1, 0) == -1){
		//cout << "���������ļ��гɹ���" << endl;
		_mkdir(str1); //�����ļ���
	}

	//�����Ӧ������Ƶ��˵����Ϣ
	char name1[80];
	sprintf_s(name1, "%s%s%s%s", pathdir, "\\", filename, ".txt");
	//string videoname = "test1_1.mp4";
	char contents[80];
	char str2[80];
	strcpy_s(str2, videoname.c_str());
	sprintf_s(contents, "%s%s%c%s%d%s%d%c%s%d", "��ƵԴ��", str2, '\n', "ʱ���(ms)��", bg, "-", ed, '\n', "֡��(֡/s)��", rate);
	FILE *fp;
	errno_t err;
	if ((err = fopen_s(&fp, name1, "w")) == 0){
		fputs(contents, fp);
		//cout << "˵����Ϣд��ɹ���" << endl;
		fclose(fp);
	}

	//���������Ƶ
	char name2[80];
	sprintf_s(name2, "%s%s%s%s", pathdir, "\\", filename, ".avi"); //�����ָ���ļ���
	cv::VideoWriter writer(name2, CV_FOURCC('D', 'I', 'V', 'X'), rate, cv::Size(inframe.cols, inframe.rows), true); //ע��˴���Ƶ�ĳߴ��СҪ����ʵ��һ��
	if (!writer.isOpened()){
		return 0;
	}

	//��2��ѭ����ʾÿһ֡
	int i = 0;
	int k = 0;
	cv::Mat fimg;
	char imagepath[80];//���洽��ͼ��·��
	while (capture.read(inframe))//����Ƶ������ɣ��˳�ѭ��
	{
		//capture >> inframe;  //��ȡ��ǰ֡
		//����Ƶ������ɣ��˳�ѭ��
		if (i*delay > ed)
		{
			break;
		}
		i++;
		if (i*delay >= bg && i*delay <= ed)
		{
			//sprintf(name, "C:\\Users\\Jordan23\\Desktop\\DataSet\\data1_1\\pictures\\%d.jpg", i);//�����ָ���ļ�����
			//imwrite(name, inframe);//���һ��jpgͼƬ������Ŀ¼��
			writer << inframe;
			//sprintf(name, "%d", i);
			//int ts = 1;
			//putText(frame, name, Point(0, 20), FONT_HERSHEY_SIMPLEX,0.6, Scalar(0, 255, 0));
			//imshow("��ȡ��Ƶ", inframe);  //��ʾ��ǰ֡
			//cout << "processing image " << k << endl;

			//������ȡ
			cv_image<bgr_pixel> cimg(inframe);
			// Detect faces   
			std::vector<rectangle> face = detector(cimg);
			//��ȡ�������ͼ��
			cv::Rect rect(face[0].left(), face[0].top(), face[0].width(), face[0].height());
			fimg = inframe(rect);

			// Detect faces
			cv_image<bgr_pixel> fcimg(fimg);
			std::vector<rectangle> faces = detector(fcimg);

			// Find the pose of each face.  
			std::vector<full_object_detection> shapes;
			for (unsigned long j = 0; j < faces.size(); ++j){
				shapes.push_back(pose_model(fcimg, faces[j]));
			}
			if (!shapes.empty()) {
				for (int j = 48; j < 68; j++) {
					circle(fimg, cvPoint(shapes[0].part(j).x(), shapes[0].part(j).y()), 2, cv::Scalar(0, 0, 255), -1);
					//putText(inframe, to_string(j), cvPoint(shapes[0].part(j).x(), shapes[0].part(j).y()), CV_FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 0, 0), 1, 4);
					//  shapes[0].part(j).x();//68��  
				}
			}
			sprintf(imagepath, "%s%s%d%s", str1, "\\lip_", k++, ".jpg");   //ָ������·��
			imwrite(imagepath, fimg);
			//Display it all on the screen
			//imshow("Dlib������", fimg);
			//cv::waitKey(delay);  //��ʱ40ms
		}
		/*if (!capture.grab())
		{
		break;
		}*/
	}
	writer.release();
	//cout << "Done!" << endl;
	//system("pause");
	return 0;
}

/*�������ݲɼ�������*/
int lip_proceess()
{
	Json::Reader reader;
	Json::Value root;// Json::Value��һ�ֺ���Ҫ�����ͣ����Դ�����������(��int, double, string, object, array)
	//���ļ��ж�ȡ  
	ifstream is;
	is.open(jsonpath, ios::binary);
	if (reader.parse(is, root))
	{
		//���岢�����������ģ��
		frontal_face_detector detector = get_frontal_face_detector();
		shape_predictor pose_model;
		deserialize("shape_predictor_68_face_landmarks.dat") >> pose_model;

		//��ȡ���ڵ�array��Ϣ
		for (unsigned int k = 0; k < root.size(); k++){
			//��ȡobject�ڵ���Ϣ
			string bg = root[k]["bg"].asString();
			string ed = root[k]["ed"].asString();
			string nc = root[k]["nc"].asString();
			string content = root[k]["onebest"].asString();
			string si = root[k]["si"].asString();
			//cout << "-----����" << si << "��" << content << endl;
			//cout << "ʱ�䷶Χ��" << bg << "-" << ed << "ms" << endl;
			//cout << "�������Ŷ�(��ΧΪ[0,1])�� " << nc << endl;

			//��ȡ������Ϣ  
			//cout << "-----�ִʽ����" << endl;
			for (unsigned int i = 0; i < root[k]["wordsResultList"].size(); i++)
			{
				string wc = root[k]["wordsResultList"][i]["wc"].asString();
				string wordBg = root[k]["wordsResultList"][i]["wordBg"].asString();
				string wordEd = root[k]["wordsResultList"][i]["wordEd"].asString();
				string wordsName = root[k]["wordsResultList"][i]["wordsName"].asString();
				//cout << "�������ݣ�" << wordsName << endl;
				//cout << "ʱ��(1֡/10ms)[֡����Χ]��" << wordBg << "-" << wordEd << endl;
				//������Ƶ���кʹ�����ȡ����
				video_cut(10 * string_to_int(wordBg), 10 * string_to_int(wordEd), wordsName, detector, pose_model);
				//cout << "�����Ŷȣ�" << wc << endl << endl;
			}
			//cout << endl << endl;
		}
		//cout << "Parsing complete!" << endl;
	}
	is.close();
	//getchar();
	return 0;
}



void LoadData::OnBnClickedProcessButton5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	lip_proceess();
	TCHAR Result1[] = _T("���ݲɼ���ɣ�������Ƶ���С�������ȡ��˵����Ϣ�ļ�");
	SetDlgItemText(IDC_RESULT_EDIT2, Result1); //��ʾ������
	//LoadData::OnCancel();
	//ResultShow showDialog;
	//showDialog.DoModal();
}


void LoadData::OnBnClickedMenu1Button1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	LoadData::OnCancel();
	CMFCtest1Dlg Menu;
	Menu.DoModal();
}


void LoadData::OnBnClickedExit1Button2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	LoadData::OnCancel();
}
