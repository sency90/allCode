namespace changePhotoDate {
    partial class MainForm {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing) {
            if (disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent() {
            this.dgvDataTable = new System.Windows.Forms.DataGridView();
            this.btnLoad = new System.Windows.Forms.Button();
            this.btnReload = new System.Windows.Forms.Button();
            this.btnSave = new System.Windows.Forms.Button();
            this.tbStatus = new System.Windows.Forms.TextBox();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.loadFilesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitwithoutSaveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutUsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.dtpCreated = new System.Windows.Forms.DateTimePicker();
            this.btnChangeAllCheckedCreatedDates = new System.Windows.Forms.Button();
            this.cbFullPath = new System.Windows.Forms.CheckBox();
            this.dtpModified = new System.Windows.Forms.DateTimePicker();
            this.dtpAccessed = new System.Windows.Forms.DateTimePicker();
            this.btnChangeAllCheckedModifiedDates = new System.Windows.Forms.Button();
            this.btnChangeAllCheckedAccessedDates = new System.Windows.Forms.Button();
            this.btnAutoChange = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dgvDataTable)).BeginInit();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // dgvDataTable
            // 
            this.dgvDataTable.AllowUserToAddRows = false;
            this.dgvDataTable.AllowUserToDeleteRows = false;
            this.dgvDataTable.AllowUserToResizeColumns = false;
            this.dgvDataTable.AllowUserToResizeRows = false;
            this.dgvDataTable.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dgvDataTable.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.AllCells;
            this.dgvDataTable.Location = new System.Drawing.Point(0, 52);
            this.dgvDataTable.Name = "dgvDataTable";
            this.dgvDataTable.Size = new System.Drawing.Size(984, 551);
            this.dgvDataTable.TabIndex = 0;
            this.dgvDataTable.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgvDataTable_CellClick);
            this.dgvDataTable.CellLeave += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgvDataTable_CellLeave);
            this.dgvDataTable.ColumnDividerWidthChanged += new System.Windows.Forms.DataGridViewColumnEventHandler(this.dgvDataTable_ColumnDividerWidthChanged);
            this.dgvDataTable.ColumnHeaderMouseClick += new System.Windows.Forms.DataGridViewCellMouseEventHandler(this.dgvDataTable_ColumnHeaderMouseClick);
            this.dgvDataTable.Scroll += new System.Windows.Forms.ScrollEventHandler(this.dgvDataTable_Scroll);
            this.dgvDataTable.Leave += new System.EventHandler(this.dgvDataTable_Leave);
            // 
            // btnLoad
            // 
            this.btnLoad.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnLoad.Location = new System.Drawing.Point(795, 23);
            this.btnLoad.Name = "btnLoad";
            this.btnLoad.Size = new System.Drawing.Size(75, 23);
            this.btnLoad.TabIndex = 1;
            this.btnLoad.Text = "&Load";
            this.btnLoad.UseVisualStyleBackColor = true;
            this.btnLoad.Click += new System.EventHandler(this.btnLoad_Click);
            // 
            // btnReload
            // 
            this.btnReload.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnReload.Enabled = false;
            this.btnReload.Location = new System.Drawing.Point(714, 23);
            this.btnReload.Name = "btnReload";
            this.btnReload.Size = new System.Drawing.Size(75, 23);
            this.btnReload.TabIndex = 3;
            this.btnReload.Text = "&Reload";
            this.btnReload.UseVisualStyleBackColor = true;
            this.btnReload.Click += new System.EventHandler(this.btnReload_Click);
            // 
            // btnSave
            // 
            this.btnSave.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnSave.Enabled = false;
            this.btnSave.Location = new System.Drawing.Point(876, 23);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(75, 23);
            this.btnSave.TabIndex = 4;
            this.btnSave.Text = "&Save";
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // tbStatus
            // 
            this.tbStatus.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.tbStatus.Location = new System.Drawing.Point(0, 671);
            this.tbStatus.Name = "tbStatus";
            this.tbStatus.Size = new System.Drawing.Size(984, 20);
            this.tbStatus.TabIndex = 5;
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(984, 24);
            this.menuStrip1.TabIndex = 6;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.loadFilesToolStripMenuItem,
            this.saveToolStripMenuItem,
            this.exitwithoutSaveToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // loadFilesToolStripMenuItem
            // 
            this.loadFilesToolStripMenuItem.Name = "loadFilesToolStripMenuItem";
            this.loadFilesToolStripMenuItem.Size = new System.Drawing.Size(170, 22);
            this.loadFilesToolStripMenuItem.Text = "&Load Files...";
            this.loadFilesToolStripMenuItem.Click += new System.EventHandler(this.loadFilesToolStripMenuItem_Click);
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(170, 22);
            this.saveToolStripMenuItem.Text = "&Save";
            this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
            // 
            // exitwithoutSaveToolStripMenuItem
            // 
            this.exitwithoutSaveToolStripMenuItem.Name = "exitwithoutSaveToolStripMenuItem";
            this.exitwithoutSaveToolStripMenuItem.Size = new System.Drawing.Size(170, 22);
            this.exitwithoutSaveToolStripMenuItem.Text = "&Exit (without save)";
            this.exitwithoutSaveToolStripMenuItem.Click += new System.EventHandler(this.exitwithoutSaveToolStripMenuItem_Click);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutUsToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.helpToolStripMenuItem.Text = "&Help";
            // 
            // aboutUsToolStripMenuItem
            // 
            this.aboutUsToolStripMenuItem.Name = "aboutUsToolStripMenuItem";
            this.aboutUsToolStripMenuItem.Size = new System.Drawing.Size(122, 22);
            this.aboutUsToolStripMenuItem.Text = "&About us";
            this.aboutUsToolStripMenuItem.Click += new System.EventHandler(this.aboutUsToolStripMenuItem_Click);
            // 
            // openFileDialog
            // 
            this.openFileDialog.FileName = "openFileDialog1";
            this.openFileDialog.Multiselect = true;
            // 
            // dtpCreated
            // 
            this.dtpCreated.CustomFormat = "yyyy-MM-dd  [HH:mm:ss]  ddd";
            this.dtpCreated.Enabled = false;
            this.dtpCreated.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpCreated.Location = new System.Drawing.Point(109, 612);
            this.dtpCreated.Name = "dtpCreated";
            this.dtpCreated.Size = new System.Drawing.Size(209, 20);
            this.dtpCreated.TabIndex = 7;
            // 
            // btnChangeAllCheckedCreatedDates
            // 
            this.btnChangeAllCheckedCreatedDates.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnChangeAllCheckedCreatedDates.Enabled = false;
            this.btnChangeAllCheckedCreatedDates.Location = new System.Drawing.Point(109, 638);
            this.btnChangeAllCheckedCreatedDates.Name = "btnChangeAllCheckedCreatedDates";
            this.btnChangeAllCheckedCreatedDates.Size = new System.Drawing.Size(209, 23);
            this.btnChangeAllCheckedCreatedDates.TabIndex = 8;
            this.btnChangeAllCheckedCreatedDates.Text = "Change All Checked Created Dates";
            this.btnChangeAllCheckedCreatedDates.UseVisualStyleBackColor = true;
            this.btnChangeAllCheckedCreatedDates.Click += new System.EventHandler(this.btnChangeAllCheckedCreatedDates_Click);
            // 
            // cbFullPath
            // 
            this.cbFullPath.AutoSize = true;
            this.cbFullPath.Location = new System.Drawing.Point(12, 27);
            this.cbFullPath.Name = "cbFullPath";
            this.cbFullPath.Size = new System.Drawing.Size(67, 17);
            this.cbFullPath.TabIndex = 9;
            this.cbFullPath.Text = "Full Path";
            this.cbFullPath.UseVisualStyleBackColor = true;
            this.cbFullPath.CheckedChanged += new System.EventHandler(this.cbFullPath_CheckedChanged);
            // 
            // dtpModified
            // 
            this.dtpModified.CustomFormat = "yyyy-MM-dd  [HH:mm:ss]  ddd";
            this.dtpModified.Enabled = false;
            this.dtpModified.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpModified.Location = new System.Drawing.Point(406, 612);
            this.dtpModified.Name = "dtpModified";
            this.dtpModified.Size = new System.Drawing.Size(209, 20);
            this.dtpModified.TabIndex = 10;
            // 
            // dtpAccessed
            // 
            this.dtpAccessed.CustomFormat = "yyyy-MM-dd  [HH:mm:ss]  ddd";
            this.dtpAccessed.Enabled = false;
            this.dtpAccessed.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpAccessed.Location = new System.Drawing.Point(694, 612);
            this.dtpAccessed.Name = "dtpAccessed";
            this.dtpAccessed.Size = new System.Drawing.Size(209, 20);
            this.dtpAccessed.TabIndex = 11;
            // 
            // btnChangeAllCheckedModifiedDates
            // 
            this.btnChangeAllCheckedModifiedDates.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnChangeAllCheckedModifiedDates.Enabled = false;
            this.btnChangeAllCheckedModifiedDates.Location = new System.Drawing.Point(406, 638);
            this.btnChangeAllCheckedModifiedDates.Name = "btnChangeAllCheckedModifiedDates";
            this.btnChangeAllCheckedModifiedDates.Size = new System.Drawing.Size(209, 23);
            this.btnChangeAllCheckedModifiedDates.TabIndex = 12;
            this.btnChangeAllCheckedModifiedDates.Text = "Change All Checked Modified Dates";
            this.btnChangeAllCheckedModifiedDates.UseVisualStyleBackColor = true;
            this.btnChangeAllCheckedModifiedDates.Click += new System.EventHandler(this.btnChangeAllCheckedModifiedDates_Click);
            // 
            // btnChangeAllCheckedAccessedDates
            // 
            this.btnChangeAllCheckedAccessedDates.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnChangeAllCheckedAccessedDates.Enabled = false;
            this.btnChangeAllCheckedAccessedDates.Location = new System.Drawing.Point(694, 638);
            this.btnChangeAllCheckedAccessedDates.Name = "btnChangeAllCheckedAccessedDates";
            this.btnChangeAllCheckedAccessedDates.Size = new System.Drawing.Size(209, 23);
            this.btnChangeAllCheckedAccessedDates.TabIndex = 13;
            this.btnChangeAllCheckedAccessedDates.Text = "Change All Checked Accessed Dates";
            this.btnChangeAllCheckedAccessedDates.UseVisualStyleBackColor = true;
            this.btnChangeAllCheckedAccessedDates.Click += new System.EventHandler(this.btnChangeAllCheckedAccessedDates_Click);
            // 
            // btnAutoChange
            // 
            this.btnAutoChange.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnAutoChange.Enabled = false;
            this.btnAutoChange.Location = new System.Drawing.Point(395, 23);
            this.btnAutoChange.Name = "btnAutoChange";
            this.btnAutoChange.Size = new System.Drawing.Size(254, 23);
            this.btnAutoChange.TabIndex = 14;
            this.btnAutoChange.Text = "&Auto Change with a Min Date";
            this.btnAutoChange.UseVisualStyleBackColor = true;
            this.btnAutoChange.Click += new System.EventHandler(this.btnAutoChange_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(984, 691);
            this.Controls.Add(this.btnAutoChange);
            this.Controls.Add(this.btnChangeAllCheckedAccessedDates);
            this.Controls.Add(this.btnChangeAllCheckedModifiedDates);
            this.Controls.Add(this.dtpAccessed);
            this.Controls.Add(this.dtpModified);
            this.Controls.Add(this.cbFullPath);
            this.Controls.Add(this.btnChangeAllCheckedCreatedDates);
            this.Controls.Add(this.dtpCreated);
            this.Controls.Add(this.tbStatus);
            this.Controls.Add(this.btnSave);
            this.Controls.Add(this.btnReload);
            this.Controls.Add(this.btnLoad);
            this.Controls.Add(this.dgvDataTable);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "MainForm";
            this.Text = "Photo Date Changing Program (made by D. H. Yang @ 2018.05.07)";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MainForm_FormClosing);
            ((System.ComponentModel.ISupportInitialize)(this.dgvDataTable)).EndInit();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dgvDataTable;
        private System.Windows.Forms.Button btnLoad;
        private System.Windows.Forms.Button btnReload;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.TextBox tbStatus;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem loadFilesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitwithoutSaveToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutUsToolStripMenuItem;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private System.Windows.Forms.DateTimePicker dtpCreated;
        private System.Windows.Forms.Button btnChangeAllCheckedCreatedDates;
        private System.Windows.Forms.CheckBox cbFullPath;
        private System.Windows.Forms.DateTimePicker dtpModified;
        private System.Windows.Forms.DateTimePicker dtpAccessed;
        private System.Windows.Forms.Button btnChangeAllCheckedModifiedDates;
        private System.Windows.Forms.Button btnChangeAllCheckedAccessedDates;
        private System.Windows.Forms.Button btnAutoChange;
    }
}

