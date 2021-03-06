#pragma once
#include "DataManager.h"
#include "DotNetUtilities.h"
#include "Method.h"



namespace Optimization {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			dataManager = new DataManager();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	public:

	protected:
		/// <summary>
		DataManager* dataManager;
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Label^  InputText;
	private: System::Windows::Forms::TextBox^  Input;
	private: System::Windows::Forms::Label^  OutputText;
	private: System::Windows::Forms::TextBox^  Output;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadEquationsToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->InputText = (gcnew System::Windows::Forms::Label());
			this->Input = (gcnew System::Windows::Forms::TextBox());
			this->OutputText = (gcnew System::Windows::Forms::Label());
			this->Output = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadEquationsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tableLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->menuStrip1, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 95)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1519, 914);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->InputText);
			this->flowLayoutPanel1->Controls->Add(this->Input);
			this->flowLayoutPanel1->Controls->Add(this->OutputText);
			this->flowLayoutPanel1->Controls->Add(this->Output);
			this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel2);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel1->Location = System::Drawing::Point(4, 49);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(1511, 861);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// InputText
			// 
			this->InputText->AutoSize = true;
			this->InputText->Location = System::Drawing::Point(4, 0);
			this->InputText->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->InputText->Name = L"InputText";
			this->InputText->Size = System::Drawing::Size(43, 18);
			this->InputText->TabIndex = 0;
			this->InputText->Text = L"Input";
			// 
			// Input
			// 
			this->Input->Location = System::Drawing::Point(55, 4);
			this->Input->Margin = System::Windows::Forms::Padding(4);
			this->Input->Multiline = true;
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(659, 507);
			this->Input->TabIndex = 1;
			// 
			// OutputText
			// 
			this->OutputText->AutoSize = true;
			this->OutputText->Location = System::Drawing::Point(722, 0);
			this->OutputText->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->OutputText->Name = L"OutputText";
			this->OutputText->Size = System::Drawing::Size(54, 18);
			this->OutputText->TabIndex = 2;
			this->OutputText->Text = L"Output";
			// 
			// Output
			// 
			this->Output->Enabled = false;
			this->Output->Location = System::Drawing::Point(784, 4);
			this->Output->Margin = System::Windows::Forms::Padding(4);
			this->Output->Multiline = true;
			this->Output->Name = L"Output";
			this->Output->Size = System::Drawing::Size(710, 507);
			this->Output->TabIndex = 3;
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Controls->Add(this->panel1);
			this->flowLayoutPanel2->Location = System::Drawing::Point(3, 518);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(1491, 335);
			this->flowLayoutPanel2->TabIndex = 4;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->textBox4);
			this->panel1->Controls->Add(this->textBox5);
			this->panel1->Controls->Add(this->textBox6);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1488, 332);
			this->panel1->TabIndex = 0;
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Powell", L"Newton", L"Quasi-Newton", L"Steep Descent ",
					L"Conjugate Gradient"
			});
			this->comboBox1->Location = System::Drawing::Point(830, 116);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(185, 36);
			this->comboBox1->TabIndex = 14;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button2->Location = System::Drawing::Point(1039, 116);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(227, 197);
			this->button2->TabIndex = 13;
			this->button2->Text = L"CALCULATE";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(591, 199);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 18);
			this->label4->TabIndex = 12;
			this->label4->Text = L"max";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(591, 163);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(34, 18);
			this->label5->TabIndex = 11;
			this->label5->Text = L"min";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(591, 127);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(42, 18);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Var6";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(338, 199);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 18);
			this->label3->TabIndex = 9;
			this->label3->Text = L"max";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(338, 163);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 18);
			this->label2->TabIndex = 8;
			this->label2->Text = L"min";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(338, 127);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 18);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Var1";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(647, 188);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(174, 29);
			this->textBox4->TabIndex = 6;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(647, 152);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(174, 29);
			this->textBox5->TabIndex = 5;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(647, 116);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(174, 29);
			this->textBox6->TabIndex = 4;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox6_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(394, 188);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(174, 29);
			this->textBox3->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(394, 152);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(174, 29);
			this->textBox2->TabIndex = 2;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(394, 116);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(174, 29);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(341, 260);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(674, 53);
			this->button1->TabIndex = 0;
			this->button1->Text = L"CLEAR";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(9, 3, 0, 3);
			this->menuStrip1->Size = System::Drawing::Size(1519, 33);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->loadEquationsToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(51, 27);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadEquationsToolStripMenuItem
			// 
			this->loadEquationsToolStripMenuItem->Name = L"loadEquationsToolStripMenuItem";
			this->loadEquationsToolStripMenuItem->Size = System::Drawing::Size(222, 30);
			this->loadEquationsToolStripMenuItem->Text = L"Load Equations";
			this->loadEquationsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadEquationsToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1519, 914);
			this->Controls->Add(this->tableLayoutPanel1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"Optimization";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void loadEquationsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		openFileDialog1->ShowDialog();
	}
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	//在Dialog按下OK便會進入此函式
	//字串轉制string^ to string
	std::string tempFileName;
	MarshalString(openFileDialog1->FileName, tempFileName);
	//將檔案路徑名稱傳入dataManager
	dataManager->SetFileName(tempFileName);
	//從讀取讀取向量資料
	if (dataManager->LoadEquationData())
	{
		std::vector<std::string> equations = dataManager->GetEquations();
		Output->Multiline = true;
		std::string tab = "\t";
		std::string line = "-------------------------------------------------------------------------------------------------------------------\n";
		for (unsigned int i = 0; i < equations.size(); i++)
		{
			dataManager->EquationsMap.insert(std::pair<int, std::string>(i, equations[i]));
			Output->Text += i.ToString();
			Output->Text += gcnew String(tab.c_str());
			Output->Text += gcnew String(equations[i].c_str());
			Output->Text += Environment::NewLine;
		}
		Output->Text += gcnew String(line.c_str());
	}
}
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	int index = this->comboBox1->SelectedIndex;
	std::string Result;
	std::vector<std::string>XVar,YVar;
	String ^ xVar = textBox1->Text; std::string xvar; MarshalString(xVar, xvar);
	String ^ xMin = textBox2->Text; std::string xmin; MarshalString(xMin, xmin);
	String ^ xMax = textBox3->Text; std::string xmax; MarshalString(xMax, xmax);
	String ^ yVar = textBox6->Text; std::string yvar; MarshalString(yVar, yvar);
	String ^ yMin = textBox5->Text; std::string ymin; MarshalString(yMin, ymin);
	String ^ yMax= textBox4->Text; std::string ymax; MarshalString(yMax, ymax);
	std::vector<double>Xvar, Yvar;
	if (index == -1)
		MessageBox::Show("Select Method!"); //input error
	else
	{
		//if has data convert to Double
		if (xvar != "")
		{
			XVar.push_back(xvar);
			XVar.push_back(xmin);
			XVar.push_back(xmax);
			for (int i = 0; i < 3; i++)
				Xvar.push_back(STRtoD(XVar[i]));
		}
		if (yvar != "")
		{
			YVar.push_back(yvar);
			YVar.push_back(ymin);
			YVar.push_back(ymax);
			for (int i = 0; i < 3; i++)
				Yvar.push_back(STRtoD(YVar[i]));
		}
		//
		String ^input = Input->Text;
		std::string temp;
		MarshalString(input, temp);
		if ((XVar.size() == 0 && YVar.size() == 0) || (temp == ""))
		{
			//Input error!!!!!!
		}
		else
		{
			std::map < std::string, std::vector<double> >VAR;
			if(YVar.size() ==0)
				VAR.insert(std::pair<std::string, std::vector<double>>("x", Xvar));
			else
			{
				VAR.insert(std::pair<std::string, std::vector<double>>("x", Xvar));
				VAR.insert(std::pair<std::string, std::vector<double>>("y", Yvar));
			}
			std::string selEquation = dataManager->EquationsMap[(int)STRtoD(temp)];
			switch (index)
			{
			case 0:
				Result = Powell(VAR,selEquation);
				break;
			case 1:
				Result = Newton(VAR, selEquation);
				break;
			case 2:
				Result = Quasi_Newton(VAR, selEquation);
				break;
			case 3:
				Result = Steep_Descent(VAR, selEquation);
				break;
			case 4:
				Result = Conjugate_Gradient(VAR, selEquation);
				break;
			default:
				break;
			}
			Output->Text += gcnew String(Result.c_str());
			Output->Text += Environment::NewLine;
			Input->Clear();
		}
		
		//do some thing
		/*for (auto i = dataManager->EquationsMap.begin(); i != dataManager->EquationsMap.end(); i++)
		{
			std::cout <<i->first<<" " << i->second << std::endl;
		}*/










		////////////////////////////////////////////////////////////////////////////////
		
	}
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	//clear
	textBox1->Clear();
	textBox2->Clear();
	textBox3->Clear();
	textBox4->Clear();
	textBox5->Clear();
	textBox6->Clear();
	Input->Clear();
	this->comboBox1->SelectedIndex = -1;
}
};
}
