using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace changePhotoDate {
    public partial class MainForm : Form {
        #region member variables
        private List<string> pathList;
        private DateTime dtTaken, dtCreated, dtModified, dtAccessed;
        private DataTable dTable, dTableOrigin;
        private List<int> minColList;
        private DateTimePicker dtp;
        private Rectangle rectangle;
        //private bool isDataChanged = false;
        private const string dateFormat = "yyyy-MM-dd  [HH:mm:ss]  ddd";
        #endregion





        /// <summary>
        /// MainForm Constructor
        /// </summary>
        public MainForm() {
            InitializeComponent();
            pathList = new List<string>();
            dTable = new DataTable();
            minColList = new List<int>();
            dtp = new DateTimePicker();

            dTable.Columns.Add(new DataColumn(ColType.CheckBox.Name, typeof(bool)));
            dTable.Columns.Add(new DataColumn(ColType.No.Name, typeof(int)));
            dTable.Columns.Add(new DataColumn(ColType.FilePath.Name, typeof(string)));
            dTable.Columns.Add(new DataColumn(ColType.DateTaken.Name, typeof(string)));
            dTable.Columns.Add(new DataColumn(ColType.DateCreated.Name, typeof(string)));
            dTable.Columns.Add(new DataColumn(ColType.DateModified.Name, typeof(string)));
            dTable.Columns.Add(new DataColumn(ColType.DateAccessed.Name, typeof(string)));

            dgvDataTable.Controls.Add(dtp);
            dtp.Visible = false;
            dtp.CustomFormat = dateFormat;
            dtp.Format = DateTimePickerFormat.Custom;
            dtp.TextChanged += new EventHandler(dtp_TextChanged);
            //dgvDataTable.EditModeChanged += new EventHandler(dtp_TextChanged);
            //dgvDataTable.KeyPress += new KeyPressEventHandler(dtp_TextChanged);

            cbFullPath.Checked = false;
        }
        private void dtp_TextChanged(object sender, EventArgs e) {
            if (dgvDataTable.CurrentCell.Value.ToString() == dtp.Text) return;
            //if (((string)dgvDataTable.CurrentCell.Value).GetHashCode() == (dtp.Text.ToString()).GetHashCode()) return;
            dgvDataTable.CurrentCell.Value = dtp.Text;
            dgvDataTable.CurrentCell.Style.ForeColor = Color.Red;
            dgvDataTable[ColType.CheckBox.Id, dgvDataTable.CurrentCell.RowIndex].Value = true;
            btnReload.Enabled = true;
            btnSave.Enabled = true;
            //isDataChanged = true;
        }







        #region Member Method
        private static DateTime DateTimeNull { get { return DateTime.MaxValue; } }
        private static Regex _r = new Regex(":");
        public static DateTime GetDateTakenFromImage(string path) {
            using (FileStream fs = new FileStream(path, FileMode.Open, FileAccess.Read))
            using (Image myImage = Image.FromStream(fs, false, false)) {
                foreach (int val in myImage.PropertyIdList) {
                    if (val == 36867) {
                        myImage.GetPropertyItem(36867);
                        PropertyItem pi = myImage.GetPropertyItem(36867);
                        string dateTaken = _r.Replace(Encoding.UTF8.GetString(pi.Value), "-", 2);
                        return DateTime.Parse(dateTaken);
                    }
                }
                return DateTimeNull;
            }
        }

        public static T DeepCopy<T>(T other) {
            using (MemoryStream ms = new MemoryStream()) {
                BinaryFormatter formatter = new BinaryFormatter();
                formatter.Serialize(ms, other);
                ms.Position = 0;
                return (T)formatter.Deserialize(ms);
            }
        }


        private void LoadFiles(string[] fileNames) {
            pathList.Clear();
            dTable.Clear();
            minColList.Clear();
            //isDataChanged = false;

            List<KeyValuePair<DateTime, int>> list_forTheEarliest = new List<KeyValuePair<DateTime, int>>();
            foreach (string path in fileNames) {
                pathList.Add(path);
                dtTaken = GetDateTakenFromImage(path);
                dtAccessed = File.GetLastAccessTime(path);
                dtCreated = File.GetCreationTime(path);
                dtModified = File.GetLastWriteTime(path);

                list_forTheEarliest.Clear();
                if (dtTaken == DateTimeNull) {
                    dTable.Rows.Add(false, dTable.Rows.Count + 1, (cbFullPath.Checked) ? path : Path.GetFileName(path), "", dtCreated.ToString(dateFormat), dtModified.ToString(dateFormat), dtAccessed.ToString(dateFormat));
                } else {
                    dTable.Rows.Add(false, dTable.Rows.Count + 1, (cbFullPath.Checked) ? path : Path.GetFileName(path), dtTaken.ToString(dateFormat), dtCreated.ToString(dateFormat), dtModified.ToString(dateFormat), dtAccessed.ToString(dateFormat));
                    list_forTheEarliest.Add(new KeyValuePair<DateTime, int>(dtTaken, ColType.DateTaken.Id));
                }
                list_forTheEarliest.Add(new KeyValuePair<DateTime, int>(dtCreated, ColType.DateCreated.Id));
                list_forTheEarliest.Add(new KeyValuePair<DateTime, int>(dtModified, ColType.DateModified.Id));
                list_forTheEarliest.Add(new KeyValuePair<DateTime, int>(dtAccessed, ColType.DateAccessed.Id));
                list_forTheEarliest.Sort((x, y) => {
                    int res = x.Key.CompareTo(y.Key);
                    if (res == 0) return x.Value.CompareTo(y.Value);
                    else return res;
                });
                //Console.WriteLine(list_forTheEarliest[0].Value.ToString());
                minColList.Add(list_forTheEarliest[0].Value);
            }

            dgvDataTable.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.DisplayedCells;
            dgvDataTable.DataSource = dTable;
            dgvDataTable.Columns[ColType.FilePath.Id].AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill;//.Fill;
            dTableOrigin = dTable.Copy();

            for (int row = 0; row < dTable.Rows.Count; row++) {
                dgvDataTable[minColList[row], row].Style.ForeColor = Color.Blue;
            }

            if (pathList.Count == 1) tbStatus.Text = "A File is opened.";
            else tbStatus.Text = "Files are opened.";

            EnableAllFunctions();
        }


        private void changeAllDates(int row, DateTime baseTime) {
            string timeString = baseTime.ToString(dateFormat);
            DataGridViewCell curCell = dgvDataTable[ColType.DateCreated.Id, row];
            if (curCell.Value.ToString() != timeString) {
                curCell.Value = timeString;
                curCell.Style.ForeColor = Color.Red;
            } else {
                curCell.Style.ForeColor = Color.Blue;
            }

            curCell = dgvDataTable[ColType.DateModified.Id, row];
            if (curCell.Value.ToString() != timeString) {
                curCell.Value = timeString;
                curCell.Style.ForeColor = Color.Red;
            } else {
                curCell.Style.ForeColor = Color.Blue;
            }

            curCell = dgvDataTable[ColType.DateAccessed.Id, row];
            if (curCell.Value.ToString() != timeString) {
                curCell.Value = timeString;
                curCell.Style.ForeColor = Color.Red;
            } else {
                curCell.Style.ForeColor = Color.Blue;
            }
        }

        private void EnableAllFunctions() {
            btnAutoChange.Enabled = true;
            btnReload.Enabled = true;
            btnSave.Enabled = true;
            dtpCreated.Enabled = true;
            dtpModified.Enabled = true;
            dtpAccessed.Enabled = true;
            btnChangeAllCheckedCreatedDates.Enabled = true;
            btnChangeAllCheckedModifiedDates.Enabled = true;
            btnChangeAllCheckedAccessedDates.Enabled = true;

        }

        #endregion





        private void cbFullPath_CheckedChanged(object sender, EventArgs e) {
            if (pathList.Count > 0) {
                for (int row = 0; row < pathList.Count; row++) {
                    dgvDataTable[ColType.FilePath.Id, row].Value = (cbFullPath.Checked) ? pathList[row] : Path.GetFileName(pathList[row]);
                    //Console.WriteLine(cbFullPath.Checked? pathList[row] : Path.GetFileName(pathList[row]));
                }
                tbStatus.Text = cbFullPath.Checked ? "Full Path Checked" : "Full Path Unchecked";
            } else tbStatus.Text = "Load files first.";
        }






        #region Button_Click
        private void btnLoad_Click(object sender, EventArgs e) {
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.Multiselect = true;
            if (dialog.ShowDialog() == DialogResult.OK) {
                LoadFiles(dialog.FileNames);
            }
            btnReload.Enabled = false;
            btnSave.Enabled = false;
        }

        private void btnChange_Click(object sender, EventArgs e) {
            if (minColList.Count != 0) {
                for (int i = 0; i < minColList.Count; i++) {
                    //if (minColList[i]
                }
            }
        }

        private void btnReload_Click(object sender, EventArgs e) {
            if (pathList.Count > 0) {
                LoadFiles(pathList.ToArray());
                //tbStatus.Text = "[OK]: Reload Complete. ";
                btnReload.Enabled = false;
                btnSave.Enabled = false;
            } else {
                tbStatus.Text = "[ERROR]: Reload Fail. --> You can RELOAD after You open file(s) at least once.";
            }
        }

        private bool TryParseExactDateTime(int col, int row, string format, out DateTime ret) {
            return DateTime.TryParseExact(dgvDataTable[col, row].Value.ToString(), format, DateTimeFormatInfo.InvariantInfo, DateTimeStyles.None, out ret);
        }

        private void btnSave_Click(object sender, EventArgs e) {
            string errLog = "";
            int changedFileCnt = 0, changedDateCnt = 0;
            for (int row = 0; row < dgvDataTable.Rows.Count; row++) {
                if (!(bool)(dgvDataTable[ColType.CheckBox.Id, row].Value)) continue;

                bool isGood = true;
                if (!TryParseExactDateTime(ColType.DateCreated.Id, row, dateFormat, out dtCreated)) isGood = false;
                if (!TryParseExactDateTime(ColType.DateModified.Id, row, dateFormat, out dtModified)) isGood = false;
                if (!TryParseExactDateTime(ColType.DateAccessed.Id, row, dateFormat, out dtAccessed)) isGood = false;
                if (!isGood) {
                    if (errLog == "") errLog = "[ERROR]: Date format is wrong. => #" + (row + 1);
                    else errLog += ", #" + (row + 1);
                    continue;
                }

                bool hasChanged = false;
                string path = pathList[row];
                DateTime orgDtCreated = File.GetCreationTime(path);
                DateTime orgDtModified = File.GetLastWriteTime(path);
                DateTime orgDtAccessed = File.GetLastAccessTime(path);
                if (DateTime.Compare(orgDtCreated, dtCreated) != 0 && DateTime.Compare(orgDtCreated, DateTimeNull)!=0) { 
                    hasChanged = true; changedDateCnt++;
                    File.SetCreationTime(path, dtCreated);
                }
                if (DateTime.Compare(orgDtModified, dtModified) != 0 && DateTime.Compare(orgDtModified, DateTimeNull)!=0) {
                    hasChanged = true; changedDateCnt++;
                    File.SetLastWriteTime(path, dtModified);
                }
                if(DateTime.Compare(orgDtAccessed, dtAccessed)!=0 && DateTime.Compare(orgDtAccessed, DateTimeNull)!=0) {
                    hasChanged = true; changedDateCnt++;
                    File.SetLastAccessTime(path, dtAccessed);
                }
                if (hasChanged) changedFileCnt++;
            }
            if (errLog != "") tbStatus.Text = errLog;
            else {
                tbStatus.Text = "[OK]: Save Complete --> Changed Date Count: " + changedDateCnt + ", Changed File Count: " + changedFileCnt;
                EnableAllFunctions();
                btnReload_Click(sender, e);
            }
        }


        private void btnChangeAllCheckedCreatedDates_Click(object sender, EventArgs e) {
            for (int row = 0; row < dgvDataTable.Rows.Count; row++) {
                if (!(bool)(dgvDataTable[ColType.CheckBox.Id, row].Value)) continue;
                DataGridViewCell curCell = dgvDataTable[ColType.DateCreated.Id, row];
                curCell.Value = dtpCreated.Text;
                curCell.Style.ForeColor = Color.Red;
            }
            tbStatus.Text = "[OK]: Change All Checked Created Dates.";
            EnableAllFunctions();
        }

        private void btnChangeAllCheckedModifiedDates_Click(object sender, EventArgs e) {
            for (int row = 0; row < dgvDataTable.Rows.Count; row++) {
                if (!(bool)(dgvDataTable[ColType.CheckBox.Id, row].Value)) continue;
                DataGridViewCell curCell = dgvDataTable[ColType.DateModified.Id, row];
                curCell.Value = dtpModified.Text;
                curCell.Style.ForeColor = Color.Red;
            }
            tbStatus.Text = "[OK]: Change All Checked Modified Dates.";
            EnableAllFunctions();
        }

        private void btnChangeAllCheckedAccessedDates_Click(object sender, EventArgs e) {
            for (int row = 0; row < dgvDataTable.Rows.Count; row++) {
                if (!(bool)(dgvDataTable[ColType.CheckBox.Id, row].Value)) continue;
                DataGridViewCell curCell = dgvDataTable[ColType.DateAccessed.Id, row];
                curCell.Value = dtpAccessed.Text;
                curCell.Style.ForeColor = Color.Red;
            }
            tbStatus.Text = "[OK]: Change All Checked Accessed Dates.";
            EnableAllFunctions();
        }


        DateTime[] tmpDt = new DateTime[5];
        DateTime mnDate;
        private void btnAutoChange_Click(object sender, EventArgs e) {
            for (int row = 0; row < dgvDataTable.Rows.Count; row++) {
                if (!(bool)(dgvDataTable[ColType.CheckBox.Id, row].Value)) continue;
                TryParseExactDateTime(ColType.DateCreated.Id, row, dateFormat, out tmpDt[1]);
                TryParseExactDateTime(ColType.DateModified.Id, row, dateFormat, out tmpDt[2]);
                TryParseExactDateTime(ColType.DateAccessed.Id, row, dateFormat, out tmpDt[3]);
                if (!TryParseExactDateTime(ColType.DateTaken.Id, row, dateFormat, out tmpDt[0])) {
                    List<DateTime> mn = new List<DateTime>();
                    mn.Add(tmpDt[1]); mn.Add(tmpDt[2]); mn.Add(tmpDt[3]);
                    mnDate = mn.Min(x => x);
                } else {
                    List<DateTime> mn = new List<DateTime>();
                    mn.Add(tmpDt[0]); mn.Add(tmpDt[1]); mn.Add(tmpDt[2]); mn.Add(tmpDt[3]);
                    mnDate = mn.Min(x => x);
                }

                changeAllDates(row, mnDate);
            }
            EnableAllFunctions();
        }

        #endregion //Button_Click







        #region dgvDataTable_ChangedOrClicked
        private void dgvDataTable_CellClick(object sender, DataGridViewCellEventArgs e) {
            //Console.WriteLine("row: {0}, col: {1}", e.RowIndex, e.ColumnIndex);
            if (e.ColumnIndex < 0) return;
            else if (e.RowIndex < 0) {
                //When clicking the checkbox header
                if (e.ColumnIndex == ColType.CheckBox.Id) {
                    bool allChecked = true;
                    foreach (DataGridViewRow row in dgvDataTable.Rows) {
                        DataGridViewCheckBoxCell chk = (DataGridViewCheckBoxCell)row.Cells[ColType.CheckBox.Id];
                        chk.Value = (chk.Value == null) ? false : (bool)chk.Value;
                        if (!(bool)chk.Value) {
                            allChecked = false;
                            break;
                        }
                    }
                    foreach (DataGridViewRow row in dgvDataTable.Rows) {
                        DataGridViewCheckBoxCell chk = (DataGridViewCheckBoxCell)row.Cells[ColType.CheckBox.Id];
                        //dgvDataTable[ColType.CheckBox.Id, row.Index].Selected = false;
                        chk.Value = !allChecked;
                        dgvDataTable.Visible = true;
                    }
                    dgvDataTable.RefreshEdit();
                } else {
                    dgvDataTable.Columns[e.ColumnIndex].SortMode = DataGridViewColumnSortMode.NotSortable;
                    return;
                }
            } else {
                //when clicking a Date cell
                if (new[] { ColType.DateCreated.Id, ColType.DateModified.Id, ColType.DateAccessed.Id }.Any(x => (x == e.ColumnIndex))) {

                    rectangle = dgvDataTable.GetCellDisplayRectangle(e.ColumnIndex, e.RowIndex, true);

                    DateTime dt = new DateTime();
                    if (!TryParseExactDateTime(e.ColumnIndex, e.RowIndex, dateFormat, out dt)) return;
                    else dtp.Value = dt;

                    if (minColList[e.RowIndex] == e.ColumnIndex) dgvDataTable[minColList[e.RowIndex], e.RowIndex].Style.ForeColor = Color.Blue;
                    dtp.Size = new Size(rectangle.Width, rectangle.Height);
                    dtp.Location = new Point(rectangle.X, rectangle.Y);
                    dtp.Visible = true;
                }
            }
        }
        private void dgvDataTable_Scroll(object sender, ScrollEventArgs e) {
            dtp.Visible = false;
        }
        private void dgvDataTable_CellLeave(object sender, DataGridViewCellEventArgs e) {
            dtp.Visible = false;
        }
        private void dgvDataTable_Leave(object sender, EventArgs e) {
            dtp.Visible = false;
        }
        private void dgvDataTable_ColumnDividerWidthChanged(object sender, DataGridViewColumnEventArgs e) {
            dtp.Visible = false;
        }

        private void dgvDataTable_ColumnHeaderMouseClick(object sender, DataGridViewCellMouseEventArgs e) {
            for (int row = 0; row < dgvDataTable.Rows.Count; row++) {
                dgvDataTable[minColList[row], row].Style.ForeColor = Color.Blue;
            }
        }

        private void MainForm_FormClosing(object sender, FormClosingEventArgs e) {
            if (btnSave.Enabled) {
                const string msg = "Are you sure you want to EXIT this program without SAVING?";
                const string caption = "Leave without saving";
                var result = MessageBox.Show(msg, caption, MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                e.Cancel = (result == DialogResult.No);
            }
        }



        #endregion //dgvDataTable_ChangedOrClicked

        #region ToolStripMenuItem_Click
        private void loadFilesToolStripMenuItem_Click(object sender, EventArgs e) {
            btnLoad_Click(sender, e);
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e) {
            btnSave_Click(sender, e);
        }

        private void exitwithoutSaveToolStripMenuItem_Click(object sender, EventArgs e) {
            this.Close();
        }

        private void aboutUsToolStripMenuItem_Click(object sender, EventArgs e) {
            tbStatus.Text = "동혁이가 현리를 위해 만들었어요~! ♡♥♡♥♡♥♡♥♡♥";
        }
        #endregion //ToolStripMenuItem_Click


    }
}
