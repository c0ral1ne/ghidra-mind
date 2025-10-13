import streamlit as st
from utils import run_ghidra

st.set_page_config(
    page_title="LLM Decompiler",
    layout="wide",
    initial_sidebar_state="expanded"
)

st.title("🧠 Ghidra Mind ")
st.write("A reverse engineering tool to decompile and reconstruct readable C source code. Powered by Ghidra + GPT-5.")

# --- File Upload Section ---
st.sidebar.header("Upload Binary")
uploaded_file = st.sidebar.file_uploader(
    "Choose a binary file",
    help="Upload the compiled binary you want to decompile"
)

# --- Decompile and reconstruct options ---
st.sidebar.header("Reconstruction Options")
opt_structs = st.sidebar.checkbox("Infer Structs", value=True)
opt_var_names = st.sidebar.checkbox("Regenerate Symbolic Variable Names", value=True)
opt_comments = st.sidebar.checkbox("Include AI-Generated Comments", value=False)
opt_style = st.sidebar.selectbox(
    "Code Style",
    ["Verbose", "Compact", "Annotated"],
    index=0
)

col1, col2 = st.sidebar.columns(2)
with col1:
    decompile_btn = st.button("Decompile", use_container_width=True, disabled=uploaded_file is None)
with col2:
    reconstruct_btn = st.button("Reconstruct", use_container_width=True, disabled=uploaded_file is None)


# --- Placeholder: Generation Statistics Table ---
# st.markdown("### 📊 Generation Statistics")
# stats_data = {
#     "Metric": ["Tokens Used", "Latency (s)", "LLM Model", "Success Rate"],
#     "Value": ["–", "–", "–", "–"]
# }
# stats_df = pd.DataFrame(stats_data)
# st.table(stats_df)

# --- Code Output Section ---
tab1, tab2 = st.tabs(["🧱 Original Decompiled", "🧠 Reconstructed (LLM)"])
with tab1:
    st.code("// Decompiled output will appear here...", language="c")

with tab2:
    st.code("// AI-reconstructed code will appear here...", language="c")




if decompile_btn and uploaded_file:
    code = run_ghidra(uploaded_file)
    st.code(code)
    # source = decompile()

if reconstruct_btn:
    st.info("Running LLM reconstruction with selected options...")
    # TODO: integrate LLM reconstruction logic here
    # Use checkboxes to adjust prompt or parameters
