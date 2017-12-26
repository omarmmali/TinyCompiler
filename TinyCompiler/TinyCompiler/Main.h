#pragma once
#include "Tokenizer.h"
#include <string>
namespace TinyCompiler {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	


	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:std::map<std::string, int>* RKW;

	public:

		Main(void)
		{
			InitializeComponent();
			RKW = new std::map<std::string, int>();
			// add Reserved Keyword To the map (coloring step)
			std::string RESERVED_WORDS[15] = {
				"int", "double", "string", "read", "write", "repeat", "until", "end",
				"if", "elseif", "else", "then", "return" , "endl" , "while" };

			for (int i = 0; i < 15; i++)
			{
				RKW->emplace(RESERVED_WORDS[i], RESERVED_WORDS[i].length());
			}
		}

	protected:

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::DataGridView^  ScanDgv;
	private: System::Windows::Forms::Button^  Compile;
	private: System::Windows::Forms::RichTextBox^  codeTxt;


	private: System::Windows::Forms::ListBox^  err;
	private: System::Windows::Forms::TabControl^  errsAndtree;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TreeView^  ParserTree;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Lexeme;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  TokenClass;
	private: System::Windows::Forms::TabPage^  Stab;
	private: System::Windows::Forms::Button^  Save;
	private: System::Windows::Forms::Button^  open;
	private: System::Windows::Forms::ImageList^  imageList1;
	private: System::ComponentModel::IContainer^  components;
	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->ScanDgv = (gcnew System::Windows::Forms::DataGridView());
			this->Lexeme = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TokenClass = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Compile = (gcnew System::Windows::Forms::Button());
			this->codeTxt = (gcnew System::Windows::Forms::RichTextBox());
			this->err = (gcnew System::Windows::Forms::ListBox());
			this->errsAndtree = (gcnew System::Windows::Forms::TabControl());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->ParserTree = (gcnew System::Windows::Forms::TreeView());
			this->Stab = (gcnew System::Windows::Forms::TabPage());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->Save = (gcnew System::Windows::Forms::Button());
			this->open = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ScanDgv))->BeginInit();
			this->errsAndtree->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->Stab->SuspendLayout();
			this->SuspendLayout();
			// 
			// ScanDgv
			// 
			this->ScanDgv->AllowUserToAddRows = false;
			this->ScanDgv->AllowUserToDeleteRows = false;
			this->ScanDgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ScanDgv->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->Lexeme, this->TokenClass });
			this->ScanDgv->Location = System::Drawing::Point(-3, -1);
			this->ScanDgv->Name = L"ScanDgv";
			this->ScanDgv->ReadOnly = true;
			this->ScanDgv->Size = System::Drawing::Size(770, 118);
			this->ScanDgv->TabIndex = 1;
			this->ScanDgv->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Main::dataGridView1_CellContentClick);
			// 
			// Lexeme
			// 
			this->Lexeme->HeaderText = L"Lexeme";
			this->Lexeme->Name = L"Lexeme";
			this->Lexeme->ReadOnly = true;
			this->Lexeme->Width = 400;
			// 
			// TokenClass
			// 
			this->TokenClass->HeaderText = L"Token Class";
			this->TokenClass->Name = L"TokenClass";
			this->TokenClass->ReadOnly = true;
			this->TokenClass->Width = 327;
			// 
			// Compile
			// 
			this->Compile->BackColor = System::Drawing::Color::Transparent;
			this->Compile->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Compile->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Compile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Compile.Image")));
			this->Compile->Location = System::Drawing::Point(159, 1);
			this->Compile->Name = L"Compile";
			this->Compile->Size = System::Drawing::Size(49, 47);
			this->Compile->TabIndex = 2;
			this->Compile->UseVisualStyleBackColor = false;
			this->Compile->Click += gcnew System::EventHandler(this, &Main::Compile_Click);
			// 
			// codeTxt
			// 
			this->codeTxt->Font = (gcnew System::Drawing::Font(L"Book Antiqua", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->codeTxt->Location = System::Drawing::Point(9, 47);
			this->codeTxt->Name = L"codeTxt";
			this->codeTxt->Size = System::Drawing::Size(768, 313);
			this->codeTxt->TabIndex = 3;
			this->codeTxt->Text = L"";
			this->codeTxt->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Main::codeTxt_MouseClick);
			this->codeTxt->TextChanged += gcnew System::EventHandler(this, &Main::codeTxt_TextChanged);
			this->codeTxt->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Main::codeTxt_KeyPress);
			// 
			// err
			// 
			this->err->FormattingEnabled = true;
			this->err->Location = System::Drawing::Point(-1, 1);
			this->err->Name = L"err";
			this->err->Size = System::Drawing::Size(767, 121);
			this->err->TabIndex = 4;
			// 
			// errsAndtree
			// 
			this->errsAndtree->Controls->Add(this->tabPage2);
			this->errsAndtree->Controls->Add(this->tabPage1);
			this->errsAndtree->Controls->Add(this->Stab);
			this->errsAndtree->ImageList = this->imageList1;
			this->errsAndtree->Location = System::Drawing::Point(10, 365);
			this->errsAndtree->Name = L"errsAndtree";
			this->errsAndtree->SelectedIndex = 0;
			this->errsAndtree->Size = System::Drawing::Size(774, 145);
			this->errsAndtree->TabIndex = 5;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->err);
			this->tabPage2->ImageIndex = 2;
			this->tabPage2->Location = System::Drawing::Point(4, 23);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(766, 118);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Errors List";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->ParserTree);
			this->tabPage1->ImageIndex = 1;
			this->tabPage1->Location = System::Drawing::Point(4, 23);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(766, 118);
			this->tabPage1->TabIndex = 2;
			this->tabPage1->Text = L"Parser Tree";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// ParserTree
			// 
			this->ParserTree->Location = System::Drawing::Point(-1, -1);
			this->ParserTree->Name = L"ParserTree";
			this->ParserTree->Size = System::Drawing::Size(767, 122);
			this->ParserTree->TabIndex = 0;
			// 
			// Stab
			// 
			this->Stab->Controls->Add(this->ScanDgv);
			this->Stab->ImageIndex = 3;
			this->Stab->Location = System::Drawing::Point(4, 23);
			this->Stab->Name = L"Stab";
			this->Stab->Padding = System::Windows::Forms::Padding(3);
			this->Stab->Size = System::Drawing::Size(766, 118);
			this->Stab->TabIndex = 3;
			this->Stab->Text = L"Scan List";
			this->Stab->UseVisualStyleBackColor = true;
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"120px-Green_Arrow_Right.svg.png");
			this->imageList1->Images->SetKeyName(1, L"business-color_hierarchy-55_icon-icons.com_53452.png");
			this->imageList1->Images->SetKeyName(2, L"dagobert83_cancel.png");
			this->imageList1->Images->SetKeyName(3, L"system-search-hi.png");
			// 
			// Save
			// 
			this->Save->BackColor = System::Drawing::Color::Transparent;
			this->Save->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Save->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Save->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Save.Image")));
			this->Save->Location = System::Drawing::Point(91, 1);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(49, 47);
			this->Save->TabIndex = 6;
			this->Save->UseVisualStyleBackColor = false;
			this->Save->Click += gcnew System::EventHandler(this, &Main::Save_Click);
			// 
			// open
			// 
			this->open->BackColor = System::Drawing::Color::Transparent;
			this->open->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->open->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->open->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"open.Image")));
			this->open->Location = System::Drawing::Point(20, 1);
			this->open->Name = L"open";
			this->open->Size = System::Drawing::Size(49, 47);
			this->open->TabIndex = 7;
			this->open->UseVisualStyleBackColor = false;
			this->open->Click += gcnew System::EventHandler(this, &Main::open_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(785, 517);
			this->Controls->Add(this->open);
			this->Controls->Add(this->Save);
			this->Controls->Add(this->errsAndtree);
			this->Controls->Add(this->codeTxt);
			this->Controls->Add(this->Compile);
			this->MaximumSize = System::Drawing::Size(801, 556);
			this->Name = L"Main";
			this->Text = L"Main";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ScanDgv))->EndInit();
			this->errsAndtree->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->Stab->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	}

private: System::Void Compile_Click(System::Object^  sender, System::EventArgs^  e) {
		std::string str = Convert(codeTxt->Text->ToString());
		Tokenizer* Tkn = new Tokenizer();
		ScanDgv->Rows->Clear();
		std::vector<Token> Tokens = Tkn->tokenize(str);
		for (int i = 0 ; i < Tokens.size() ; i++)
		{

			String^ Lex = gcnew String(Tokens[i].lexeme.c_str());
			String^ Type = gcnew String(Token::token_name(Tokens[i].token_type).c_str());

			if (Type == "WHITESPACE")
				continue;

			if (Type == "INVALID_TOKEN")
			{
				err->Items->Add(Lex + Type);
				continue;
			}

			ScanDgv->Rows->Add(Lex , Type);
		}
		// coloring
		int index;
		int start = 0;
		while ((index = codeTxt->Text->IndexOf("int",start)) != -1)
		{
			codeTxt->Select(index, 3);
			codeTxt->SelectionColor = Color::RoyalBlue;
			start = index + 3;
		}
	}
private: std::string Convert(String ^ s)
	 {
		 std::string r = "";
		 for (int i = 0; i < s->Length ; i++)
		 {
			 char x = (s->ToCharArray())[i];
			 r += x;
		 }
		 return r;
	 }
private: System::Void codeTxt_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void codeTxt_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	HorizontalAlignment x = codeTxt->SelectionAlignment;
	int i = codeTxt->SelectionStart;
	if (e->KeyChar == ';' || e->KeyChar == ' ')
	{		
		for (std::map<std::string, int>::iterator it = RKW->begin(); it != RKW->end(); it++)
		{
			int index;
			int start = 0;

			String^ name = gcnew String((it->first).c_str());
			int len = it->second;

			while ((index = codeTxt->Text->IndexOf((name), start)) != -1)
			{
				codeTxt->Select(index, len);
				codeTxt->SelectionColor = Color::RoyalBlue;
				start = index + len;
			}
		}

		codeTxt->SelectionAlignment = x;
		codeTxt->SelectionStart = i;
		codeTxt->SelectionColor = Color::Black;
	
	}

}
private: System::Void codeTxt_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
}
private: System::Void open_Click(System::Object^  sender, System::EventArgs^  e) {
	Stream^  myStream;
	String^ m;
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
	openFileDialog1->InitialDirectory = "c:\\";
	openFileDialog1->Filter = "Tiny File|*.TINY";
	openFileDialog1->RestoreDirectory = true;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream = openFileDialog1->OpenFile()) != nullptr)
		{
			std::ifstream file(Convert(openFileDialog1->FileName));
			std::string line;
			std::string text;
			while (std::getline(file, line))
			{
				text += line;
				text += "\n";
			}
			String^ TXT = gcnew String(text.c_str());
			codeTxt->Text = TXT;
			codeTxt->Refresh();
			file.close();
		}
	}
}
private: System::Void Save_Click(System::Object^  sender, System::EventArgs^  e) {
	Stream^  myStream;
	String^ m;
	SaveFileDialog^ SFD = gcnew SaveFileDialog();
	SFD->InitialDirectory = ".\\saves";
	SFD->Filter = "Tiny File|*.TINY";
	if (SFD->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream = SFD->OpenFile()) != nullptr)
		{
			FileInfo^ fi = gcnew FileInfo(SFD->FileName);
			std::string name;
			
			name = Convert(fi->Name);
			std::ofstream file(".\\saves\\" + name);
			file << Convert(codeTxt->Text);
			file.close();
		}
	}
}
};
}
